#pragma once
#include "ICommand.h"
#include "Selector.h"
#include "Unit.h"

class InputHandler {
public:
	InputHandler();
	void UpdateKeyState();

	ICommand* SelectorHandleInput(Selector* selector);
	ICommand* UnitHandleInput(Unit* unit);

	bool CheckUndoStatus();

private:
	char keys_[256] = {0};
	char preKeys_[256] = {0};

	Selector* selector_;
	Unit* selectedUnit_;
};