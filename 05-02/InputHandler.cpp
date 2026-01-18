#include "InputHandler.h"
#include "Novice.h"

InputHandler::InputHandler() {}

void InputHandler::UpdateKeyState() {}

ICommand* InputHandler::SelectorHandleInput(Selector* selector) { return nullptr; }

ICommand* InputHandler::UnitHandleInput(Unit* unit) {
	if (keys_[DIK_D] && !preKeys_[DIK_D]) {
		
	}

	if (keys_[DIK_A] && !preKeys_[DIK_A]) {
		
	}

	return nullptr;
}

bool InputHandler::CheckUndoStatus() { return false; }
