#include "Enemy.h"
#include "Novice.h"

void Enemy::Initialize() {
	radius_ = 24.0f;
	pos_ = {radius_, radius_};
	speed_ = 4.0f;
	direction_ = Direction::RIGHT;
}

void Enemy::Update() {
	// 左右移動
	if (direction_ == Direction::RIGHT) {
		pos_.x += speed_;
	} else if (direction_ == Direction::LEFT) {
		pos_.x -= speed_;
	}

	// 反転処理
	if (pos_.x >= 1280.0f - radius_) {
		direction_ = Direction::LEFT;
	} else if (pos_.x <= radius_) {
		direction_ = Direction::RIGHT;
	}
}

void Enemy::Draw() { Novice::DrawEllipse(static_cast<int>(pos_.x), static_cast<int>(pos_.y), static_cast<int>(radius_), static_cast<int>(radius_), 0, 0xaaaaaaff, kFillModeSolid); }