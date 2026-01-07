#include "Player.h"
#include "Novice.h"

void Player::Initialize() {
	pos_ = {640.0f, 360.0f};
	speed_ = 5.0f;
	size_ = {16.0f, 16.0f};
}

void Player::Update() {
	// 右移動
	MoveRight();
	// 左移動
	MoveLeft();
}

void Player::Draw() {
	Novice::DrawBox(static_cast<int>(pos_.x - size_.x / 2), static_cast<int>(pos_.y - size_.y / 2), static_cast<int>(size_.x), static_cast<int>(size_.y), 0.0f, WHITE, kFillModeSolid);
}

void Player::MoveRight() { pos_.x += speed_; }

void Player::MoveLeft() { pos_.x -= speed_; }