#include <iostream>
#include <cmath>

#include "Rectangle.h"

Rectangle::Rectangle(): Rectangle(0, 0) {}

Rectangle::Rectangle(size_t a, size_t b) :
	side_a(a), side_b(b) {
	std::cout << "Rectangle created: " << side_a << ", " << side_b << std::endl;
}

Rectangle::Rectangle(std::istream& is) {
	is >> side_a;
	is >> side_b;
	std::cout << "Rectangle successfuly read" << std::endl;
}

Rectangle::Rectangle(const Rectangle& orig) {
	side_a = orig.side_a;
	side_b = orig.side_b;
	std::cout << "Rectangle successfuly copied" << std::endl;
}

double Rectangle::Square() {
	return side_a * side_b;
}

void Rectangle::Print() {
	std::cout << "sides: a = " << side_a << " b = " << side_b << std::endl;
}

Rectangle::~Rectangle() {
	std::cout << "Rectangle deleted" << std::endl;
}