#pragma once
#include "IScene.h"

class ClearScene : public IScene {
	void Initialize(InputManager* input) override;
	void Update() override;
	void Draw() override;

private:
	InputManager* input_;
};