#pragma once
#include <string>

class Car {
public:
	virtual ~Car();

	virtual void Initialize(std::string name);

	virtual void PrintName();

protected:
	std::string name_;
};
