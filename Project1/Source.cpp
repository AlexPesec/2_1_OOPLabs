#include <iostream>
#include <cstdlib>

#include "Square.h"

int main() {
	Figure *ptr = new Square(2);
	ptr->Print();
	std::cout << ptr->Square << std::endl;
	delete ptr;
	return 0;
}