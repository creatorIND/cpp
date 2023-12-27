#include <iostream>
#include <memory>
#include <vector>

class Test {
private:
	int data;
public:
	Test() : data{0} {
		std::cout << "\tTest constructor (" << data << ")" << std::endl;
	}
	Test(int data) : data{data} {
		std::cout << "\tTest constructor (" << data << ")" << std::endl;
	}
	int getData() const {
		return data;
	}
	~Test() {
		std::cout << "Test destructor (" << data << ")" << std::endl;
	}
};

//Function prototypes
auto make();
void fill(std::vector<std::shared_ptr<Test>> &vec, int num);
void display(const std::vector<std::shared_ptr<Test>> &vec);

auto make() {
	return std::make_unique<std::vector<std::shared_ptr<Test>>>();
}

void fill(std::vector<std::shared_ptr<Test>> &vec, int num) {
	for(int i {0}; i < num; i++) {
		int data {};
		std::cout << "Enter data point [" << (i + 1) << "]: ";
		std::cin >> data;
		vec.push_back(std::make_shared<Test>(data));
	}
}

void display(const std::vector<std::shared_ptr<Test>> &vec) {
	std::cout << "\nDisplaying vector data" << std::endl;
	std::cout << "==========================" << std::endl;
	for(const auto &ptr: vec) {
		std::cout << ptr->getData() << std::endl;
	}
	std::cout << "==========================" << std::endl;
}

int main() {
	std::unique_ptr<std::vector<std::shared_ptr<Test>>> vecPtr;
	vecPtr = make();
	std::cout << "How many data points do you want to enter? ";
	int num {};
	std::cin >> num;
	fill(*vecPtr, num);
	display(*vecPtr);
	
	std::cout << std::endl;
	return 0;
}