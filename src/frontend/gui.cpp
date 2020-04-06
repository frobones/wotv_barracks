
//!
//! @file gui.cpp
//!
//! @author https://github.com/frobones
//! @date 4/5/20
//!

#include <Wt/WAnimation.h>
#include <Wt/WPanel.h>
#include <Wt/WText.h>

#include <rapidjson/document.h>
#include <rapidjson/filereadstream.h>

#include "syslog.h"

#include "database/dbo.hpp"
#include "database/unit.hpp"
#include "gui.hpp"
#include "helper.hpp"

using namespace rapidjson;

/*
 * The env argument contains information about the new session, and
 * the initial request. It must be passed to the WApplication
 * constructor so it is typically also an argument for your custom
 * application constructor.
*/
BarracksApplication::BarracksApplication(const WEnvironment& env, const char *json_file_path) : WApplication(env) {
  setlogmask(LOG_UPTO(LOG_NOTICE));
  openlog(__FILE__, LOG_CONS | LOG_PID | LOG_NDELAY, LOG_USER);

  useStyleSheet(WLink("https://www.w3schools.com/w3css/4/w3.css"));

  // Open JSON file that contains the information to populate the Database
  FILE* fp = fopen(json_file_path, "rb");
  if (fp == nullptr) {
    syslog(LOG_ERR, "%s:%d fp is null", __func__, __LINE__);
    return;
  }

  // Read the file
  char readBuffer[65536];
  FileReadStream is(fp, readBuffer, sizeof(readBuffer));

  // Parse the file
  Document json_object;
  json_object.ParseStream(is);

  // Initialize Database with JSON data
  Database db;
  db.Init(json_object);

  // Add units to Screen
  for (auto &unit_info : json_object["units"].GetArray()) {
    dbo::ptr<Unit> unit = db.GetUnitByName(unit_info["name"].GetString());

    if (unit)
      root()->addWidget(helper::get_unit_frame(unit.get()));
  }
}
