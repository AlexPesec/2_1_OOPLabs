#include <iostream>
#include <cmath>

#include "Square.h"

Square::Square(): Square(0) {}

Square::Square(size_t a):
	side(a) {
	std::cout << "Square created: " << side << std::endl;
}

Square::Square(std::istream& is) {
	is >> side
	std::cout << "Square successfuly read" << std:endl;
}

Square::Square(const Square& orig) {
	side = orig.side;
	std::cout << "Square successfuly copied" << std::endl;
}

double Square::Square() {
	return side * side;
}

void Square::Print() {
	std::cout << "side = " << side << std::endl;
}

Square::~Square() {
	std::cout << "Square deleted" << std::endl;
}