#include <iostream>
#include <vector>

//Abstract Base class
class Shape {
private:
	//attributes common to all shapes
	
public:
	virtual void draw() = 0; //pure virtual function
	virtual void rotate() = 0; //pure virtual function
	virtual ~Shape() {}
};

//Abstract class
class Open_Shape: public Shape {
public:
	virtual ~Open_Shape() {}
};

//Abstract class
class Closed_Shape: public Shape {
public:
	virtual ~Closed_Shape() {}
};

//Concrete class
class Line: public Open_Shape {
	virtual void draw() override {
		std::cout << "Drawing a line" << std::endl;
	}
	virtual void rotate() override {
		std::cout << "Rotating a line" << std::endl;
	}
	virtual ~Line() {}
};

//Concrete class
class Circle: public Closed_Shape {
public:
	virtual void draw() override {
		std::cout << "Drawing a circle" << std::endl;
	}
	virtual void rotate() override {
		std::cout << "Rotating a circle" << std::endl;
	}
	virtual ~Circle() {}
};

//Concrete class
class Square: public Closed_Shape {
public:
	virtual void draw() override {
		std::cout << "Drawing a square" << std::endl;
	}
	virtual void rotate() override {
		std::cout << "Rotating a square" << std::endl;
	}
	virtual ~Square() {}
};

void screenRefresh(const std::vector<Shape *> &shapes) {
	std::cout << "Refreshing" << std::endl;
	for(const auto p: shapes) {
		p->draw();
	}
}

int main() {
//	Shape s;
//	Shape *p = new Shape();
	
//	Circle c;
//	c.draw();
	
//	Shape *ptr = new Circle();
//	ptr->draw();
//	ptr->rotate();
	
	Shape *s1 = new Circle();
	Shape *s2 = new Line();
	Shape *s3 = new Square();
	
	std::vector<Shape *> shapes {s1, s2, s3};
//	for(const auto p: shapes) {
//		p->draw();
//	}
	
	screenRefresh(shapes);
	
	delete s1;
	delete s2;
	delete s3;
	
	return 0;
}