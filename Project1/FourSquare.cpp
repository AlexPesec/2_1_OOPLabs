#include <iostream>
#include <cmath>

#include "FourSquare.h"

FourSquare::FourSquare(): FourSquare(0) {}

FourSquare::FourSquare(size_t a):
	side(a) {
	std::cout << "Foursquare created: " << side << std::endl;
}

FourSquare::FourSquare(std::istream& is) {
	is >> side;
	std::cout << "FourSquare successfuly read" << std::endl;
}

FourSquare::FourSquare(const FourSquare& orig) {
	side = orig.side;
	std::cout << "Foursquare successfuly copied" << std::endl;
}

bool operator==(const FourSquare& left, const FourSquare& right) {
	return left.side - right.side;
}

FourSquare& FourSquare::operator=(const FourSquare& right) {
	if (this == &right) return *this;
	std::cout << "Foursquare copied" << std::endl;
	this->side = right.side;
	return *this;
}

FourSquare operator+(const FourSquare& left, const FourSquare& right) {
	return FourSquare(left.side + right.side);
}

std::ostream& operator<<(std::ostream& os, const FourSquare& obj) {
	os << "Side = " << obj.side << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, FourSquare& obj) {
	is >> obj.side;
	return is;
}


double FourSquare::Square() {
	return side * side;
}

void FourSquare::Print() {
	std::cout << "Type of figure: Foursquare\nSide = " << side << std::endl;
}

FourSquare::~FourSquare() {
	std::cout << "Foursquare deleted" << std::endl;
}