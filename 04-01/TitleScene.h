#pragma once
#include "IScene.h"

class TitleScene : public IScene {
public:
	void Initialize(InputManager* input) override;
	void Update() override;
	void Draw() override;

private:
	InputManager* input_;
};