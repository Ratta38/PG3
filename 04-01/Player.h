#pragma once
#include "Bullet.h"
#include "InputManager.h"
#include "Vector2.h"
#include <memory>

class Player {
public:
	void Initialize();
	void Update(InputManager* input);
	void Draw();

	// Getter
	Bullet* GetBullet() const { return bullet_.get(); }
	Vector2 GetBulletPos() const { return bullet_->GetPos(); }
	float GetBulletCollisionRadius() const { return bullet_->GetCollisionRadius(); }

private:
	void Shot(InputManager* input);

private:
	// 座標
	Vector2 pos_;

	// サイズ
	Vector2 size_;

	// 速さ
	float speed_;

	// 弾
	std::unique_ptr<Bullet> bullet_;
};