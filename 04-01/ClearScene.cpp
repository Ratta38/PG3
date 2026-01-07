#include "ClearScene.h"
#include "InputManager.h"
#include "Novice.h"

void ClearScene::Initialize(InputManager* input) { input_ = input; }

void ClearScene::Update() {
	if (input_->IsTrigger(DIK_SPACE)) {
		sceneNo = TITLE;
	}
}

void ClearScene::Draw() {
	Novice::DrawBox(0, 0, 1280, 720, 0, BLACK, kFillModeSolid);
	Novice::ScreenPrintf(0, 0, "ClearScene");
}