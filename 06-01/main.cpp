#include <iostream>
#include <string>
#include <thread>
#include <functional>

void Print(int num) { 
	std::cout << "thread" + std::to_string(num) << std::endl; 
}

int main() {
	// thread1
	std::thread th1(Print, 1);
	th1.join();

	// thread2
	std::thread th2(Print, 2);
	th2.join();

	// thread3
	std::thread th3(Print, 3);
	th3.join();

	return 0;
}