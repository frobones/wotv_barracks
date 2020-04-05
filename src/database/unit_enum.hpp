
//!
//! @file unit_enum.hpp
//!
//! @author https://github.com/frobones
//! @date 4/5/20
//!

#ifndef WOTV_BARRACKS_DATABASE_UNIT_ENUM_HPP_
#define WOTV_BARRACKS_DATABASE_UNIT_ENUM_HPP_

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

#endif // WOTV_BARRACKS_DATABASE_UNIT_ENUM_HPP_
