
//!
//! @file helper.hpp
//!
//! @author https://github.com/frobones
//! @date 4/5/20
//!

#ifndef WOTV_BARRACKS_FRONTEND_HELPER_HPP_
#define WOTV_BARRACKS_FRONTEND_HELPER_HPP_

#include <Wt/WContainerWidget.h>

#include "database/unit.hpp"

using namespace Wt;

class helper {
public:
  static std::unique_ptr<WPanel> get_unit_frame(const Unit *unit);
};

#endif // WOTV_BARRACKS_FRONTEND_HELPER_HPP_
