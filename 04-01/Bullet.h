#pragma once
#include "Vector2.h"

class Bullet {
public:
	void Initialize(Vector2 pos);
	void Update();
	void Draw();

	// Getter
	Vector2 GetPos() const { return pos_; }
	float GetCollisionRadius() const { return size_.x; }

private:
	// 座標
	Vector2 pos_;

	// サイズ
	Vector2 size_;

	// 速さ
	float speed_;
};