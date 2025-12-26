#include "Car.h"
#include <iostream>

Car::~Car() {}

void Car::Initialize(std::string name) { name_ = name; }

void Car::PrintName() { std::cout << name_ << std::endl; }
