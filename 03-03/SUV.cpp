#include "SUV.h"
#include <iostream>

void SUV::Initialize(std::string name) { name_ = name; }

void SUV::PrintName() { std::cout << name_ << std::endl; }
