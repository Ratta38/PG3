#pragma once
#include "Vector2.h"

enum class Direction { RIGHT, LEFT };

class Enemy {
public:
	void Initialize();
	void Update();
	void Draw();

	// Getter
	Vector2 GetPos() const { return pos_; }
	float GetRadius() const { return radius_; }

private:
	// 座標
	Vector2 pos_;

	// 半径
	float radius_;

	// 速さ
	float speed_;

	// 敵の進む方向
	Direction direction_;
};