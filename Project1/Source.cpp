#include <iostream>
#include <cstdlib>

#include "FourSquare.h"
#include "Rectangle.h"
#include "Trapeze.h"

int main() {
	while (true) {
		std::cout << "Enter number:\n1 - for Foursquare\n2 - for Rectangle\n3 - for Trapeze\n4 - to exit the programm" << std::endl;
		int n;
		std::cin >> n;
		Figure* ptr;
		if (n == 1) ptr = new FourSquare(2);
		else if (n == 2) ptr = new Rectangle(2, 2);
		else if (n == 3) ptr = new Trapeze(2, 3, 2, 2);
		else if (n == 4) break;
		else {
			std::cout << "Bad input, try again\n" << std::endl;
			continue;
		}
		ptr->Print();
		std::cout << ptr->Square() << std::endl;
		delete ptr;
	}
	return 0;
}