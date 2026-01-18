#include "Unit.h"
#include "Novice.h"
#include "Selector.h"

void Unit::Init(int idref) {}

void Unit::Update() {}

void Unit::Draw() {
	// 選択状況に応じて色を変える
	unsigned int color = isSelected_ ? WHITE : RED;

	Novice::DrawBox(mapX_, mapY_, mapSize_, mapSize_, 0.0f, color, kFillModeSolid);
}

void Unit::Move(int x, int y) {}

void Unit::MoveEnd(Selector* selector) {}
