#include <stdio.h>
#include <iostream>
#include <algorithm>

template <typename Type>

Type Min(Type a, Type b)
{
	return std::min(a, b);
}

int main()
{
	// int型比較
	std::cout << "int" << std::endl;
	std::cout << Min(12, 25) << "\n\n";

	// float型比較
	std::cout << "float" << std::endl;
	std::cout << Min(20.6f, 4.5f) << "f" << "\n\n";

	// double型比較
	std::cout << "double" << std::endl;
	std::cout << Min(14.6, 77.8) << "\n\n";

	return 0;
}