#include <iostream>

class Base {
public:
	virtual void sayHello() const {
		std::cout << "Hello - I'm a Base class object" << std::endl;
	}
	virtual ~Base() {}
};

class Derived: public Base {
public:
	virtual void sayHello() const override {
		std::cout << "Hello - I'm a Derived class object" << std::endl;
	}
	virtual ~Derived() {}
};

int main() {
	Base *p1 = new Base();
	p1->sayHello();
	
	Derived *p2 = new Derived();
	p2->sayHello();
	
	Base *p3 = new Derived();
	p3->sayHello();
	
	return 0;
}