#include "Bullet.h"
#include "Novice.h"

void Bullet::Initialize(Vector2 pos) {
	pos_ = pos;
	size_ = {5.0f, 8.0f};
	speed_ = 7.0f;
}

void Bullet::Update() { pos_.y -= speed_; }

void Bullet::Draw() {
	Novice::DrawTriangle(
	    static_cast<int>(pos_.x), static_cast<int>(pos_.y - size_.y), static_cast<int>(pos_.x - size_.x), static_cast<int>(pos_.y + size_.y), static_cast<int>(pos_.x + size_.x),
	    static_cast<int>(pos_.y + size_.y), WHITE, kFillModeSolid);
}