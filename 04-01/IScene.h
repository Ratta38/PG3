#pragma once
#include "InputManager.h"

enum Scene { TITLE = 0, STAGE = 1, CLEAR = 2 };

class IScene {
public:
	virtual ~IScene() = default;

	virtual void Initialize(InputManager* input) = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	// シーン番号のゲッター
	int GetSceneNo();

protected:
	// シーン番号
	static int sceneNo;
};