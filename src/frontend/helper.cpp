
//!
//! @file helper.cpp
//!
//! @author https://github.com/frobones
//! @date 4/5/20
//!

#include <Wt/WPanel.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WImage.h>
#include <Wt/WLink.h>
#include <Wt/WText.h>

#include "helper.hpp"

std::unique_ptr<WPanel> helper::get_unit_frame(const Unit *unit) {
  auto container = std::make_unique<WContainerWidget>();

  container->addNew<WImage>(WLink(unit->GetImageUri().c_str()));
  container->addNew<WText>(WString("<p>Element: {1}</p>").arg(unit->GetElement()));
  container->addNew<WText>(WString("<p>Faction: {1}</p>").arg(unit->GetFaction()));
  container->addNew<WText>(WString("<p>Rarity: {1}</p>").arg(unit->GetRarity()));
  container->addNew<WText>(WString("<p>Job 1: {1}</p>").arg(unit->GetJob1()));
  container->addNew<WText>(WString("<p>Job 2: {1}</p>").arg(unit->GetJob2()));
  container->addNew<WText>(WString("<p>Job 3: {1}</p>").arg(unit->GetJob3()));

  auto panel = std::make_unique<WPanel>();
  panel->setTitle(unit->GetName());
  panel->addStyleClass("centered-example");
  panel->setCollapsible(true);

  Wt::WAnimation animation(Wt::AnimationEffect::SlideInFromTop,
                           Wt::TimingFunction::EaseOut,
                           100);

  panel->setAnimation(animation);
  panel->setCentralWidget(std::move(container));

  return panel;
}
