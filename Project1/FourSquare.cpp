#include <iostream>
#include <cmath>

#include "FourSquare.h"

FourSquare::FourSquare(): FourSquare(0) {}

FourSquare::FourSquare(size_t a):
	side(a) {
	std::cout << "Square created: " << side << std::endl;
}

FourSquare::FourSquare(std::istream& is) {
	is >> side;
	std::cout << "Square successfuly read" << std::endl;
}

FourSquare::FourSquare(const FourSquare& orig) {
	side = orig.side;
	std::cout << "Square successfuly copied" << std::endl;
}

double FourSquare::Square() {
	return side * side;
}

void FourSquare::Print() {
	std::cout << "side = " << side << std::endl;
}

FourSquare::~FourSquare() {
	std::cout << "Square deleted" << std::endl;
}