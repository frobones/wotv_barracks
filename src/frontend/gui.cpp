
//!
//! @file gui.cpp
//!
//! @author https://github.com/frobones
//! @date 4/5/20
//!

#include <Wt/WAnimation.h>
#include <Wt/WPanel.h>
#include <Wt/WText.h>

#include "syslog.h"

#include "database/dbo.hpp"
#include "database/unit.hpp"
#include "gui.hpp"
#include "helper.hpp"

/*
 * The env argument contains information about the new session, and
 * the initial request. It must be passed to the WApplication
 * constructor so it is typically also an argument for your custom
 * application constructor.
*/
BarracksApplication::BarracksApplication(const WEnvironment& env, const char *json_file_path) : WApplication(env) {
  setlogmask(LOG_UPTO(LOG_NOTICE));
  openlog(__FILE__, LOG_CONS | LOG_PID | LOG_NDELAY, LOG_USER);

  Database db;

  if (db.Init(json_file_path) != 0) {
    syslog(LOG_ERR, "%s:%d Database failed to initialize\n", __func__, __LINE__);
    return;
  }

  dbo::ptr<Unit> unit = db.GetUnit();

  useStyleSheet(WLink("https://www.w3schools.com/w3css/4/w3.css"));

  if (unit)
    root()->addWidget(helper::get_unit_frame(unit.get()));
}
