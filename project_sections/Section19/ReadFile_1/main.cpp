#include <iostream>
#include <fstream>

int main() {
	std::ifstream inFile;
	std::string line;
	int num {};
	double total {};
	
	inFile.open("test.txt");
	if(!inFile) {
		std::cerr << "Problem opening file!" << std::endl;
		return 1;
	}
	
	inFile >> line >> num >> total;
	
	std::cout << line << std::endl;
	std::cout << num << std::endl;
	std::cout << total << std::endl;
	
	inFile.close();
	
	return 0;
}