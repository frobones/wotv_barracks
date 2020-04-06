
//!
//! @file unit.hpp
//!
//! @author https://github.com/frobones
//! @date 4/5/20
//!

#ifndef WOTV_BARRACKS_DATABASE_UNIT_HPP_
#define WOTV_BARRACKS_DATABASE_UNIT_HPP_

#include <Wt/Dbo/Dbo.h>

#include <string>

#include "unit_enum.hpp"

namespace dbo = Wt::Dbo;

class Unit {
 public:
  std::string name_;
  Faction faction_;
  bool is_limited_;
  Rarity rarity_;
  Element element_;
  Job job_1_;
  Job job_2_;
  Job job_3_;
  std::string image_uri;

  const char *GetName() const;
  const char *GetFaction() const;
  const char *GetRarity() const;
  const char *GetElement() const;
  const char *GetJob1() const;
  const char *GetJob2() const;
  const char *GetJob3() const;
  std::string GetImageUri() const;

  template<class Action>
  void persist(Action &a) {
    dbo::field(a, name_, "name");
    dbo::field(a, faction_, "faction");
    dbo::field(a, is_limited_, "isLimited");
    dbo::field(a, rarity_, "rarity");
    dbo::field(a, element_, "element");
    dbo::field(a, job_1_, "job_1");
    dbo::field(a, job_2_, "job_2");
    dbo::field(a, job_3_, "job_3");
  }

 private:
  const char *GetJob(Job job) const;
};


#endif // WOTV_BARRACKS_DATABASE_UNIT_HPP_
