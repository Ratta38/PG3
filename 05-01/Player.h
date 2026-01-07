#pragma once
#include "Vector2.h"
#include <memory>

class Player {
public:
	void Initialize();
	void Update();
	void Draw();
	void MoveRight();
	void MoveLeft();

private:
	// 座標
	Vector2 pos_;

	// 速さ
	float speed_;

	// サイズ
	Vector2 size_;
};