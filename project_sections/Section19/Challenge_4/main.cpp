#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

int main() {
	std::ifstream inFile {"romeoandjuliet.txt"};
	std::ofstream outFile {"romeoandjuliet_out.txt"};
	
	if(!inFile.is_open()) {
		std::cerr << "Error opening input file" << std::endl;
		return 1;
	}
	if(!outFile.is_open()) {
		std::cerr << "Error opening output file" << std::endl;
		return 1;
	}
	
	std::string line;
	size_t count {0};
	while(std::getline(inFile, line)) {
		if(line.length() == 0) {
			outFile << std::endl;
		}
		else {
			count++;
			outFile << std::setw(7) << std::left << count << line << std::endl;
		}
	}
	
	std::cout << "File copied" << std::endl;
	
	inFile.close();
	outFile.close();
	
	return 0;
}