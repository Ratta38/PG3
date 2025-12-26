#pragma once
#include "Car.h"

class SUV : public Car {
public:
	void Initialize(std::string name) override;

	void PrintName() override;
};
