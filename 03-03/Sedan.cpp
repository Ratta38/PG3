#include "Sedan.h"
#include <iostream>

void Sedan::Initialize(std::string name) { name_ = name; }

void Sedan::PrintName() { std::cout << name_ << std::endl; }
