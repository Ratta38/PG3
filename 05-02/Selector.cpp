#include "Selector.h"
#include "Novice.h"
#include "Unit.h"

Selector::Selector() {}

void Selector::Init(){}

void Selector::Update(){}

void Selector::Draw(){
	// ワイヤーフレームで四角形を描画
	Novice::DrawBox(mapX_, mapY_, mapSize_, mapSize_, 0.0f, RED, kFillModeWireFrame);
}

void Selector::Move(int x, int y){}

void Selector::SelectUnit() {}