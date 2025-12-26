#pragma once
#include "IShape.h"

class Rectangle : public IShape {
public:
	void Size() override;

	void Draw() override;

private:
	float width_ = 2.0f;
	float height_ = 4.0f;
};