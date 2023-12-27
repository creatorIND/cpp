//Stream Manipulators - Boolean

#include <iostream>
#include <iomanip>

int main() {
	std::cout << "noboolalpha - default (10 == 10): " << (10 == 10) << std::endl;
	std::cout << "noboolalpha - default (10 == 20): " << (10 == 20) << std::endl;
	
	//Set to true/false formatting
	std::cout << std::boolalpha;
	std::cout << "boolalpha (10 == 10): " << (10 == 10) << std::endl;
	std::cout << "boolalpha (10 == 20): " << (10 == 20) << std::endl;
	
	//Setting still stays for the future boolean insertions
	std::cout << "boolalpha (10 == 10): " << (10 == 10) << std::endl;
	std::cout << "boolalpha (10 == 20): " << (10 == 20) << std::endl;
	
	//Toggle to 0/1
	std::cout << std::noboolalpha;
	std::cout << "noboolalpha (10 == 10): " << (10 == 10) << std::endl;
	std::cout << "noboolalpha (10 == 20): " << (10 == 20) << std::endl; 
	
	//Set back to true/false using setf method
	std::cout.setf(std::ios::boolalpha);
	std::cout << "boolalpha (10 == 10): " << (10 == 10) << std::endl;
	std::cout << "boolalpha (10 == 20): " << (10 == 20) << std::endl;
	
	//Resets to default which is 0/1
	std::cout << std::resetiosflags(std::ios::boolalpha);
	std::cout << "Default (10 == 10): " << (10 == 10) << std::endl;
	std::cout << "Default (10 == 20): " << (10 == 20) << std::endl;
}