#include <iostream>
#include <fstream>
#include <string>

int main() {
	std::ifstream inFile {"poem.txt"};
	std::ofstream outFile {"poem_out.txt"};
	if(!inFile) {
		std::cerr << "Error opening input file" << std::endl;
		return 1;
	}
	if(!outFile) {
		std::cerr << "Error opening output file" << std::endl;
		return 1;
	}
	
//	std::string line {};
//	while(std::getline(inFile, line)) {
//		outFile << line << std::endl;
//	}
	
	char c;
	while(inFile.get(c)) {
		outFile.put(c);
	}
	
	std::cout << "File copied" << std::endl;
	inFile.close();
	outFile.close();
	
	return 0;
}