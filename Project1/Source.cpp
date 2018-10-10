#include <iostream>
#include <cstdlib>

#include "FourSquare.h"

int main() {
	Figure* ptr;

	ptr = new FourSquare(2);
	ptr->Print();
	std::cout << ptr->Square() << std::endl;
	delete ptr;

	return 0;
}