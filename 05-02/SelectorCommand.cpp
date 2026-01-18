#include "SelectorCommand.h"

SelectorMoveCommand::SelectorMoveCommand(Selector* selector, int x, int y) {}

void SelectorMoveCommand::Exec() {}

SelectUnitCommand::SelectUnitCommand(Selector* selector) {}

void SelectUnitCommand::Exec() {}

UnitMoveCommand::UnitMoveCommand(Unit* unit, int x, int y) {}

void UnitMoveCommand::Exec() {}

UnitMoveEndCommand::UnitMoveEndCommand(Unit* unit, Selector* selector) {}

void UnitMoveEndCommand::Exec() {}
