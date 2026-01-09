#pragma once
#include "ICommand.h"
#include "Selector.h"
#include "Unit.h"

class SelectorMoveCommand : public ICommand {
public:
	SelectorMoveCommand(Selector* selector, int x, int y);
	void Exec() override;

private:
	Selector* selector_;
	int x_;
	int y_;
};

class SelectUnitCommand : public ICommand {
public:
	SelectUnitCommand(Selector* selector);
	void Exec() override;

private:
	Selector* selector_;
};

class UnitMoveCommand : public ICommand {
public:
	UnitMoveCommand(Unit* unit, int x, int y);
	void Exec() override;

private:
	Unit* unit_;
	int x_;
	int y_;
};

class UnitMoveEndCommand : public ICommand {
public:
	UnitMoveEndCommand(Unit* unit, Selector* selector);
	void Exec() override;

private:
	Unit* unit_;
	Selector* selector_;
};