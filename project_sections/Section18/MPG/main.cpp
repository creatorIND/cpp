//Miles Per Gallon - No Exception Handling

#include <iostream>

int main() {
	int miles {};
	int gallons {};
	double milesPerGallon {};
	
	std::cout << "Enter the miles: ";
	std::cin >> miles;
	std::cout << "Enter the gallons: ";
	std::cin >> gallons;
	
//	milesPerGallon = miles / gallons;
	if(gallons != 0) {
		milesPerGallon = static_cast<double>(miles) / gallons;
		std::cout << "Result: " << milesPerGallon << std::endl;
	}
	else {
		std::cerr << "Sorry, can't divide by zero" << std::endl;
	}
	
	std::cout << "Bye!" << std::endl;
	return 0;
}