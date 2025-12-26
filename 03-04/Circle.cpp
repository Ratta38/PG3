#include "Circle.h"
#include <iostream>
#include <numbers>

void Circle::Size() { area_ = radius_ * radius_ * std::numbers::pi_v<float>; }

void Circle::Draw() { std::cout << "円の面積: " << area_ << "c㎡" << std::endl; }
