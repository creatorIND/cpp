#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

int main() {
	std::ifstream inFile;
	inFile.open("responses.txt");
	if(!inFile) {
		std::cerr << "Problem opening file" << std::endl;
		return 1;
	}
	
	std::string answerKey {}, response {}, name {};
	int total {}, maxMarks {5};
	inFile >> answerKey;
	int maxField {20}, field1 {15}, field2 {5};
	std::cout << std::setw(field1) << std::left << "Student"
			  << std::setw(field2) << std::right << "Score"
			  << std::endl;
	std::cout << std::setw(maxField) << std::setfill('-') << ""
			  << std::endl;
	std::cout << std::setfill(' ');
	while(inFile >> name >> response) {
		int count {0};
		for(size_t i {0}; i < answerKey.length(); i++) {
			if(response.at(i) == answerKey.at(i)) {
				count++;
				total++;
			}
		}
		std::cout << std::setw(field1) << std::left << name
				  << std::setw(field2) << std::right << count
				  << std::endl;
	}
	std::cout << std::setw(maxField) << std::setfill('-') << ""
			  << std::endl;
	std::cout << std::setfill(' ');
	std::cout << std::setw(field1) << std::left << "Average Score"
			  << std::setw(field2) << std::right << (static_cast<double>(total) / maxMarks)
			  << std::endl;
	
	inFile.close();
	std::cout << std::endl << std::endl;
	return 0;
}