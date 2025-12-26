#include "Box.h"
#include <iostream>
#include <string>

int main() {
	Box<int, int> b1(10, 20);
	Box<int, float> b2(12, 5.0f);
	Box<int, double> b3(1, 2.34);
	Box<float, float> b4(40.0f, 39.0f);
	Box<float, double> b5(10.0f, 9.0);
	Box<double, double> b6(10.0, 20.0);

	std::cout << b1.Min() << std::endl;
	std::cout << b2.Min() << std::endl;
	std::cout << b3.Min() << std::endl;
	std::cout << b4.Min() << std::endl;
	std::cout << b5.Min() << std::endl;
	std::cout << b6.Min() << std::endl;

	return 0;
}