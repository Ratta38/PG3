#pragma once
#include "Car.h"

class Sedan : public Car {
public:
	void Initialize(std::string name) override;

	void PrintName() override;
};
