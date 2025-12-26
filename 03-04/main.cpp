#include "Circle.h"
#include "Rectangle.h"
#include <memory>

int main() {
	// インスタンス生成
	std::unique_ptr<Circle> circle = std::make_unique<Circle>();
	std::unique_ptr<Rectangle> rectangle = std::make_unique<Rectangle>();

	// 面積を求める
	circle->Size();
	rectangle->Size();

	// 表示
	circle->Draw();
	rectangle->Draw();

	return 0;
}