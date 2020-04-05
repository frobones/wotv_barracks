
//!
//! @file gui.cpp
//!
//! @author https://github.com/frobones
//! @date 4/5/20
//!

#include <Wt/WAnimation.h>
#include <Wt/WPanel.h>
#include <Wt/WText.h>

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
BarracksApplication::BarracksApplication(const WEnvironment& env) : WApplication(env) {
  Database db;
  db.Init("/home/frobones/CLionProjects/wotv_barracks/json/units.json");

  dbo::ptr<Unit> unit = db.GetUnit();

  useStyleSheet(WLink("https://www.w3schools.com/w3css/4/w3.css"));

  if (unit)
    root()->addWidget(helper::get_unit_frame(unit.get()));
}
