
//!
//! @file unit.cpp
//!
//! @author https://github.com/frobones
//! @date 4/5/20
//!

#include "unit.hpp"

const char *Unit::GetName() const {
  return name_.c_str();
}

const char *Unit::GetFaction() const {
  switch (faction_) {
    case Faction::ALIARE:
      return "Aliare";
    case Faction::CRYSTAL_SANCTUM:
      return "Crystal Sanctum";
    case Faction::FENNES:
      return "Fennes";
    case Faction::FFBE:
      return "FFBE";
    case Faction::FFXIV:
      return "FFXIV";
    case Faction::GOUGA:
      return "Gouga";
    case Faction::HOURNE:
      return "Hourne";
    case Faction::LEONIS:
      return "Leonis";
    case Faction::OVIS:
      return "Ovis";
    case Faction::SAIGA:
      return "Saiga";
    case Faction::WEZETTE:
      return "Wezette";
    default:
      return "UNKNOWN";
  }
}

const char *Unit::GetRarity() const {
  switch (rarity_) {
    case Rarity::N:
      return "N";
    case Rarity::R:
      return "R";
    case Rarity::SR:
      return "SR";
    case Rarity::MR:
      return "MR";
    case Rarity::UR:
      return "UR";
    default:
      return "UNKNOWN";
  }
}

const char *Unit::GetElement() const {
  switch (element_) {
    case Element::FIRE:
      return "Fire";
    case Element::ICE:
      return "Ice";
    case Element::WIND:
      return "Wind";
    case Element::EARTH:
      return "Earth";
    case Element::LIGHTNING:
      return "Lightning";
    case Element::WATER:
      return "Water";
    case Element::LIGHT:
      return "Light";
    case Element::DARK:
      return "Dark";
    default:
      return "UNKNOWN";
  }
}

const char *Unit::GetJob(Job job) const {
  switch (job) {
    case Job::BLACK_MAGE:
      return "Black Mage";
    case Job::CLERIC:
      return "Cleric";
    case Job::DRAGOON:
      return "Dragoon";
    case Job::GREEN_MAGE:
      return "Green Mage";
    case Job::GUNBREAKER:
      return "Gunbreaker";
    case Job::GUNNER:
      return "Gunner";
    case Job::HUNTER:
      return "Hunter";
    case Job::KNIGHT:
      return "Knight";
    case Job::LANCER:
      return "Lancer";
    case Job::LORD:
      return "Lord";
    case Job::MONK:
      return "Monk";
    case Job::NINJA:
      return "Ninja";
    case Job::PALADIN:
      return "Paladin";
    case Job::RANGER:
      return "Ranger";
    case Job::RED_MAGE:
      return "Red Mage";
    case Job::SAMURAI:
      return "Samurai";
    case Job::SORCERESS:
      return "Sorceress";
    case Job::SOLDIER:
      return "Soldier";
    case Job::SPELLBLADE:
      return "Spellblade";
    case Job::THIEF:
      return "Thief";
    case Job::TIME_MAGE:
      return "Time Mage";
    case Job::WARRIOR:
      return "Warrior";
    case Job::WINGED_ONE:
      return "Winged One";
    case Job::WHITE_MAGE:
      return "White Mage";
    case Job::WHITE_MAGE_OF_LAPIS:
      return "White Mage of Lapis";
    default:
      return "UNKNOWN";
  }
}

const char *Unit::GetJob1() const {
  return GetJob(job_1_);
}

const char *Unit::GetJob2() const {
  return GetJob(job_2_);
}

const char *Unit::GetJob3() const {
  return GetJob(job_3_);
}

const char *Unit::GetImageUri() const {
  return image_uri.c_str();
}
