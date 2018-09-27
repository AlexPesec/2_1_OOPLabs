#include <iostream>
#include <cstdlib>

#include "FourSquare.h"
#include "Rectangle.h"
#include "Trapeze.h"

int main() {
	Figure* ptr;

	ptr = new FourSquare(2);
	ptr->Print();
	std::cout << ptr->Square() << std::endl;
	delete ptr;

	ptr = new Rectangle(2, 2);
	ptr->Print();
	std::cout << ptr->Square() << std::endl;
	delete ptr;

	ptr = new Trapeze(2, 2, 2, 2, 2);
	ptr->Print();
	std::cout << ptr->Square() << std::endl;
	delete ptr;

	return 0;
}