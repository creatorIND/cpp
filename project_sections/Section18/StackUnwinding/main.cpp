//Stack Unwinding
#include <iostream>

void funcA();
void funcB();
void funcC();

void funcA() {
	std::cout << "Starting funcA" << std::endl;
	funcB();
	std::cout << "Ending funcA" << std::endl;
}

void funcB() {
	std::cout << "Starting funcB" << std::endl;
	try {
		funcC();
	}
	catch(int &ex) {
		std::cout << "Caught error in funcB" << std::endl;
	}
	std::cout << "Ending funcB" << std::endl;
}

void funcC() {
	std::cout << "Starting funcC" << std::endl;
	throw 100;
	std::cout << "Ending funcC" << std::endl;
}

int main() {
	std::cout << "Starting main" << std::endl;
	try {
		funcA();
	}
	catch(int &ex) {
		std::cout << "Caught error in main" << std::endl;
	}
	std::cout << "Finishing main" << std::endl;
	return 0;
}