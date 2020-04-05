
//!
//! @file dbo.hpp
//!
//! @author https://github.com/frobones
//! @date 4/5/20
//!

#ifndef WOTV_BARRACKS_DATABASE_DBO_HPP_
#define _DBO_HPP_

#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/backend/Sqlite3.h>

#include "unit.hpp"

namespace dbo = Wt::Dbo;

class Database {
public:
  Database();
  void Init(const char*);

  dbo::ptr<Unit> GetUnit();

private:
  dbo::Session session;
};

#endif // WOTV_BARRACKS_DATABASE_DBO_HPP_
