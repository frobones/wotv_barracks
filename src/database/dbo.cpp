
//!
//! @file dbo.cpp
//!
//! @author https://github.com/frobones
//! @date 4/5/20
//!

#include <string>
#include <cstdio>
#include <syslog.h>

#include <rapidjson/document.h>
#include <rapidjson/filereadstream.h>

#include "dbo.hpp"
#include "unit.hpp"

using namespace rapidjson;

Database::Database() {
  setlogmask(LOG_UPTO(LOG_NOTICE));
  openlog(__FILE__, LOG_CONS | LOG_PID | LOG_NDELAY, LOG_USER);

  std::unique_ptr<dbo::backend::Sqlite3> sqlite3(new dbo::backend::Sqlite3(":memory:"));

  session.setConnection(std::move(sqlite3));
  session.mapClass<Unit>("unit");
  session.createTables();
}

Database::~Database() {
  closelog();
}

int Database::Init(const char *json_info) {
  {
    dbo::Transaction transaction(session);

    std::unique_ptr<Unit> unit{new Unit()};

    FILE* fp = fopen(json_info, "rb");

    if (fp == nullptr) {
      syslog(LOG_ERR, "%s:%d fp is null", __func__, __LINE__);
      return -EINVAL;
    }

    char readBuffer[65536];
    FileReadStream is(fp, readBuffer, sizeof(readBuffer));

    Document d;
    d.ParseStream(is);

    auto units = d["units"].GetArray();

    for (auto const& unit_info : units) {
      unit->name_ = unit_info["name"].GetString();
      unit->faction_ = toEnum<Faction>(unit_info["faction"].GetString());
      unit->is_limited_ = unit_info["is_limited"].GetBool();
      unit->rarity_ = toEnum<Rarity>(unit_info["rarity"].GetString());
      unit->element_ = toEnum<Element>(unit_info["element"].GetString());
      unit->job_1_ = toEnum<Job>(unit_info["jobs"][0].GetString());
      unit->job_2_ = toEnum<Job>(unit_info["jobs"][1].GetString());
      unit->job_3_ = toEnum<Job>(unit_info["jobs"][2].GetString());
      unit->image_uri = unit_info["image_uri"].GetString();
    }

    dbo::ptr<Unit> unit_ptr = session.add(std::move(unit));
  }

  return 0;
}

dbo::ptr<Unit> Database::GetUnit() {
  {
    dbo::Transaction transaction(session);
    return session.find<Unit>().where("name = ?").bind("Mont Leonis");
  }
}

