#include <iostream>
#include <cmath>

#include "FourSquare.h"

FourSquare::FourSquare(): FourSquare(0) {}

FourSquare::FourSquare(size_t a):
	side(a) {
	this->typ = 0;
	//std::cout << "Foursquare created: " << side << std::endl;
}

FourSquare::FourSquare(std::istream& is) {
	is >> side;
	typ = 0;
	//std::cout << "FourSquare successfuly read" << std::endl;
}

FourSquare::FourSquare(const FourSquare& orig) {
	this->side = orig.side;
	typ = 0;
	//std::cout << "Foursquare successfuly copied" << std::endl;
}

FourSquare& FourSquare::operator=(const FourSquare& right) {
	if (this == &right) return *this;
	//std::cout << "Foursquare copied" << std::endl;
	this->side = right.side;
	return *this;
}

FourSquare operator+(const FourSquare& left, const FourSquare& right) {
	return FourSquare(left.side + right.side);
}

std::ostream& operator<<(std::ostream& os, const FourSquare& obj) {
	os << "Type of figure: Foursquare\nSide = " << obj.side << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, FourSquare& obj) {
	obj = FourSquare(is);
	return is;
}

double FourSquare::Square() const {
	return side * side;
}

size_t FourSquare::Type() const {
	return this->typ;
}

std::ostream& FourSquare::Print(std::ostream& os) const {
	os << *this;
	return os;
}

std::istream& FourSquare::Scan(std::istream& is) {
	is >> *this;
	return is;
}

FourSquare::~FourSquare() {
	//std::cout << "Foursquare deleted" << std::endl;
}