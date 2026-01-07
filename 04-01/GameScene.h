#pragma once
#include "Enemy.h"
#include "IScene.h"
#include "Player.h"
#include <memory>

class GameScene : public IScene {
	void Initialize(InputManager* input) override;
	void Update() override;
	void Draw() override;

private:
	InputManager* input_;

	// プレイヤー
	std::unique_ptr<Player> player_;

	// 敵
	std::unique_ptr<Enemy> enemy_;
};