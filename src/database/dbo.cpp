
//!
//! @file dbo.cpp
//!
//! @author https://github.com/frobones
//! @date 4/5/20
//!

#include <string>

#include "dbo.hpp"
#include "unit.hpp"

Database::Database() {
  std::unique_ptr<dbo::backend::Sqlite3> sqlite3(new dbo::backend::Sqlite3(":memory:"));

  session.setConnection(std::move(sqlite3));
  session.mapClass<Unit>("unit");
  session.createTables();
}

void Database::Init() {
  {
    dbo::Transaction transaction(session);

    std::unique_ptr<Unit> unit{new Unit()};
    unit->name_ = "Mont Leonis";
    unit->faction_ = Faction::LEONIS;
    unit->is_limited_ = false;
    unit->rarity_ = Rarity::MR;
    unit->element_ = Element::EARTH;
    unit->job_1_ = Job::LORD;
    unit->job_2_ = Job::PALADIN;
    unit->job_3_ = Job::KNIGHT;
    unit->image_uri = "http://wotvffbe.gamea.co/file/imgbank/fm874m0k/426irsj7/e120d9b9def38020a4fdbcd1628e887d963b1da7_s.jpg";

    dbo::ptr<Unit> unit_ptr = session.add(std::move(unit));
  }
}

dbo::ptr<Unit> Database::GetUnit() {
  {
    dbo::Transaction transaction(session);
    return session.find<Unit>().where("name = ?").bind("Mont Leonis");
  }
}
