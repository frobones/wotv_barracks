
//!
//! @file gui.hpp
//!
//! @author https://github.com/frobones
//! @date 4/5/20
//!

#ifndef WOTV_BARRACKS_FRONTEND_GUI_HPP_
#define WOTV_BARRACKS_FRONTEND_GUI_HPP_

#include <Wt/WApplication.h>
#include <Wt/WBreak.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>

using namespace Wt;

class BarracksApplication : public WApplication {
public:
  BarracksApplication(const WEnvironment &env);
};

#endif // WOTV_BARRACKS_FRONTEND_GUI_HPP_
