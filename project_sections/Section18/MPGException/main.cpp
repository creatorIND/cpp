//Miles Per Gallon - With Exception Handling

#include <iostream>

int main() {
	int miles {};
	int gallons {};
	double milesPerGallon {};
	
	std::cout << "Enter the miles: ";
	std::cin >> miles;
	std::cout << "Enter the gallons: ";
	std::cin >> gallons;
	
	try {
		if(gallons == 0) {
			throw 0;
		}
		milesPerGallon = static_cast<double>(miles) / gallons;
		std::cout << "Result: " << milesPerGallon << std::endl;
	}
	catch(int &ex) {
		std::cerr << "Sorry, you can't divide by zero" << std::endl;
	}
	
	std::cout << "Bye!" << std::endl;
	return 0;
}