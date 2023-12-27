#include <iostream>
#include <fstream>

int main() {
	std::ifstream inFile;
	inFile.open("poem.txt");
	if(!inFile) {
		std::cerr << "Problem opening file" << std::endl;
		return 1;
	}
	
	char c;
	while(inFile.get(c)) {
		std::cout << c;
	}
	
	inFile.close();
	std::cout << std::endl << std::endl;
	return 0;
}