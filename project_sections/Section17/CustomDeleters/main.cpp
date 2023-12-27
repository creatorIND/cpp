#include <iostream>
#include <memory>

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
		std::cout << "\tTest destructor (" << data << ")" << std::endl;
	}
};

void myDeleter(Test *ptr) {
	std::cout << "\tUsing my custom function deleter" << std::endl;
	delete ptr;
}

int main() {
	{
		//Using a function
		std::shared_ptr<Test> ptr1 {new Test {100}, myDeleter};
	}
	
	std::cout << "=============================================" << std::endl;
	
	{
		//Using a lambda expression
		std::shared_ptr<Test> ptr2 (new Test {1000},
		[] (Test *ptr) {
			std::cout << "\tUsing my custom lambda deleter" << std::endl;
			delete ptr;
		});
	}
	std::cout << std::endl;
	return 0;
}