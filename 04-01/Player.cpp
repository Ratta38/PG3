#include "Player.h"
#include "Novice.h"
#include <cmath>

void Player::Initialize() {
	pos_ = {640.0f, 360.0f};
	size_ = {32.0f, 32.0f};
	speed_ = 5.0f;
}

void Player::Update(InputManager* input) {
	float dx = 0.0f;
	float dy = 0.0f;

	if (input->GetKeys()[DIK_D])
		dx += 1.0f;
	if (input->GetKeys()[DIK_A])
		dx -= 1.0f;
	if (input->GetKeys()[DIK_W])
		dy -= 1.0f;
	if (input->GetKeys()[DIK_S])
		dy += 1.0f;

	// 斜め移動の速度補正
	float len = std::sqrtf(dx * dx + dy * dy);
	if (len != 0.0f) {
		dx /= len;
		dy /= len;
	}

	pos_.x += dx * speed_;
	pos_.y += dy * speed_;

	// 弾の生成
	Shot(input);

	if (bullet_) {
		// 弾の更新処理
		bullet_->Update();

		// 弾の削除
		if (bullet_->GetPos().y < 0.0f) {
			bullet_ = nullptr;
		}
	}
}

void Player::Draw() {
	Novice::DrawBox(static_cast<int>(pos_.x - size_.x / 2), static_cast<int>(pos_.y - size_.y / 2), static_cast<int>(size_.x), static_cast<int>(size_.y), 0, WHITE, kFillModeSolid);

	// 弾の描画処理
	if (bullet_)
		bullet_->Draw();
}

void Player::Shot(InputManager* input) {
	// 弾がすでに生成されていれば早期リターン
	if (bullet_)
		return;

	if (input->IsTrigger(DIK_SPACE)) {
		bullet_ = std::make_unique<Bullet>();

		// プレイヤーより少し前に弾を生成するための余白
		float margin = 2.0f;
		bullet_->Initialize({pos_.x, pos_.y - margin});
	}
}