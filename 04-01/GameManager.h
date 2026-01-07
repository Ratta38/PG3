#pragma once
#include "ClearScene.h"
#include "GameScene.h"
#include "IScene.h"
#include "InputManager.h"
#include "TitleScene.h"
#include <memory>

class GameManager {
public:
	GameManager();
	~GameManager();

	int Run();

private:
	// シーンを保持するメンバ変数
	std::unique_ptr<IScene> sceneArr_[3];

	// どのステージを呼び出すかを管理する変数
	int currentSceneNo_; // 現在のシーン
	int prevSceneNo_;    // 前のシーン

	// インプットマネージャー
	std::unique_ptr<InputManager> input_;
};