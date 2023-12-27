#include <iostream>
#include <iomanip>
#include <fstream>

int main() {
	std::ifstream inFile;
	std::string line;
	int num;
	double total;
	
	inFile.open("test.txt");
	if(!inFile) {
		std::cerr << "Problem opening file" << std::endl;
		return 1;
	}
	while(inFile >> line >> num >> total) {
		std::cout << std::setw(10) << std::left << line
			  << std::setw(10) << num
			  << std::setw(10) << total
			  << std::endl;
	}
	
	inFile.close();
	
	return 0;
}