#include "GameScene.h"
#include "InputManager.h"
#include "Novice.h"
#include <cmath>

void GameScene::Initialize(InputManager* input) {
	input_ = input;

	// プレイヤー
	player_ = std::make_unique<Player>();
	player_->Initialize();

	// 敵
	enemy_ = std::make_unique<Enemy>();
	enemy_->Initialize();
}

void GameScene::Update() {
	// プレイヤー更新処理
	player_->Update(input_);

	// 敵の更新処理
	enemy_->Update();

	// プレイヤーの弾と敵の当たり判定
	{
		if (!player_->GetBullet())
			return;

		float disX = player_->GetBulletPos().x - enemy_->GetPos().x;
		float disY = player_->GetBulletPos().y - enemy_->GetPos().y;
		float dis = std::sqrtf((disX * disX) + (disY * disY));

		if (dis <= player_->GetBulletCollisionRadius() + enemy_->GetRadius()) {
			sceneNo = CLEAR; // 弾が敵に当たったらシーン切り替え
		}
	}
}

void GameScene::Draw() {
	Novice::DrawBox(0, 0, 1280, 720, 0, BLACK, kFillModeSolid);
	Novice::ScreenPrintf(0, 0, "GameScene");

	// プレイヤー描画処理
	player_->Draw();

	// 敵の描画処理
	enemy_->Draw();
}