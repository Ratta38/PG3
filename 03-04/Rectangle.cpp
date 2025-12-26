#include "Rectangle.h"
#include <iostream>

void Rectangle::Size() { area_ = width_ * height_; }

void Rectangle::Draw() { std::cout << "矩形の面積: " << area_ << "c㎡" << std::endl; }
