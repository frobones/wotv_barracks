
//!
//! @file unit_enum.hpp
//!
//! @author https://github.com/frobones
//! @date 4/5/20
//!

#ifndef WOTV_BARRACKS_DATABASE_UNIT_ENUM_HPP_
#define WOTV_BARRACKS_DATABASE_UNIT_ENUM_HPP_

#include <string>
#include <map>

enum class Rarity {
  N = 0,
  R,
  SR,
  MR,
  UR
};

enum class Element {
  FIRE = 0,
  ICE,
  WIND,
  EARTH,
  LIGHTNING,
  WATER,
  LIGHT,
  DARK
};

enum class Faction {
  ALIARE = 0,
  CRYSTAL_SANCTUM,
  FENNES,
  FFBE,
  FFXIV,
  GOUGA,
  HOURNE,
  LEONIS,
  OVIS,
  SAIGA,
  WEZETTE
};

enum class Job {
  BLACK_MAGE = 0,
  CLERIC,
  DRAGOON,
  GREEN_MAGE,
  GUNBREAKER,
  GUNNER,
  HUNTER,
  KNIGHT,
  LANCER,
  LORD,
  MONK,
  NINJA,
  PALADIN,
  RANGER,
  RED_MAGE,
  SAMURAI,
  SORCERESS,
  SOLDIER,
  SPELLBLADE,
  THIEF,
  TIME_MAGE,
  WARRIOR,
  WINGED_ONE,
  WHITE_MAGE,
  WHITE_MAGE_OF_LAPIS
};

template <typename T>
T toEnum(std::string value) {

  if (std::is_same<T, Rarity>::value) {
    std::map<std::string, Rarity > map;

    map["N"]  = Rarity::N;
    map["R"]  = Rarity::R;
    map["SR"] = Rarity::SR;
    map["MR"] = Rarity::MR;
    map["UR"] = Rarity::UR;

    return static_cast<T>(map[value]);
  }

  if (std::is_same<T, Element>::value) {
    std::map<std::string, Element > map;

    map["Fire"]      = Element::FIRE;
    map["Ice"]       = Element ::ICE;
    map["Wind"]      = Element::WIND;
    map["Earth"]     = Element::EARTH;
    map["Lightning"] = Element::LIGHTNING;
    map["Water"]     = Element::WATER;
    map["Light"]     = Element::LIGHT;
    map["Dark"]      = Element::DARK;

    return static_cast<T>(map[value]);
  }

  if (std::is_same<T,Faction>::value) {
    std::map<std::string, Faction > map;

    map["Aliare"]          = Faction::ALIARE;
    map["Crystal Sanctum"] = Faction::CRYSTAL_SANCTUM;
    map["Fennes"]          = Faction::FENNES;
    map["FFBE"]            = Faction::FFBE;
    map["FFXIV"]           = Faction::FFXIV;
    map["Gouga"]           = Faction::GOUGA;
    map["Hourne"]          = Faction::HOURNE;
    map["Leonis"]          = Faction::LEONIS;
    map["Ovis"]            = Faction::OVIS;
    map["Saiga"]           = Faction::SAIGA;
    map["Wezette"]         = Faction::WEZETTE;

    return static_cast<T>(map[value]);
  }

  if (std::is_same<T,Job>::value) {
    std::map<std::string, Job > map;

    map["Black Mage"]          = Job::BLACK_MAGE;
    map["Cleirc"]              = Job::CLERIC;
    map["Dragoon"]             = Job::DRAGOON;
    map["Green Mage"]          = Job::GREEN_MAGE;
    map["Gunbreaker"]          = Job::GUNBREAKER;
    map["Gunner"]              = Job::GUNNER;
    map["Hunter"]              = Job::HUNTER;
    map["Knight"]              = Job::KNIGHT;
    map["Lancer"]              = Job::LANCER;
    map["Lord"]                = Job::LORD;
    map["Monk"]                = Job::MONK;
    map["Ninja"]               = Job::NINJA;
    map["Paladin"]             = Job::PALADIN;
    map["Ranger"]              = Job::RANGER;
    map["Red Mage"]            = Job::RED_MAGE;
    map["Samurai"]             = Job::SAMURAI;
    map["Sorceress"]           = Job::SORCERESS;
    map["Soldier"]             = Job::SOLDIER;
    map["Spellblade"]          = Job::SPELLBLADE;
    map["Thief"]               = Job::THIEF;
    map["Time Mage"]           = Job::TIME_MAGE;
    map["Warrior"]             = Job::WARRIOR;
    map["Winged One"]          = Job::WINGED_ONE;
    map["White Mage"]          = Job::WHITE_MAGE;
    map["White Mage of Lapis"] = Job::WHITE_MAGE_OF_LAPIS;

    return static_cast<T>(map[value]);
  }
}

#endif // WOTV_BARRACKS_DATABASE_UNIT_ENUM_HPP_
