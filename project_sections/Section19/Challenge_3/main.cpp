#include <iostream>
#include <string>
#include <fstream>

int main() {
	std::ifstream inFile;
	inFile.open("romeoandjuliet.txt");
	if(!inFile) {
		std::cerr << "Problem opening file" << std::endl;
		return 1;
	}
	std::cout << "Enter the substring to search for: ";
	std::string wordToFind {};
	std::cin >> wordToFind;
	
	std::string eachWord {};
	int totalWords {}, wordMatched {};
	while(inFile >> eachWord) {
		++totalWords;
		size_t found = eachWord.find(wordToFind);
		if(found != std::string::npos) {
			wordMatched++;
		}
	}
	std::cout << totalWords << " words were searched..." << std::endl;
	std::cout << "The substring " << wordToFind << " was found " << wordMatched << " times" << std::endl;
	
	inFile.close();
	std::cout << std::endl;
	return 0;
}