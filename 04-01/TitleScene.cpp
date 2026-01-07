#include "TitleScene.h"
#include "Novice.h"

void TitleScene::Initialize(InputManager* input) { input_ = input; }

void TitleScene::Update() {
	if (input_->IsTrigger(DIK_SPACE)) {
		sceneNo = STAGE;
	}
}

void TitleScene::Draw() {
	Novice::DrawBox(0, 0, 1280, 720, 0, BLACK, kFillModeSolid);
	Novice::ScreenPrintf(0, 0, "TitleScene");
}