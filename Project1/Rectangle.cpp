#include <iostream>
#include <cmath>

#include "Rectangle.h"

Rectangle::Rectangle(): Rectangle(0, 0) {}

Rectangle::Rectangle(size_t a, size_t b) :
	side_a(a), side_b(b) {
	this->typ = 1;
	//std::cout << "Rectangle created: " << side_a << ", " << side_b << std::endl;
}

Rectangle::Rectangle(std::istream& is) {
	is >> side_a;
	is >> side_b;
	typ = 1;
	//std::cout << "Rectangle successfuly read" << std::endl;
}

Rectangle::Rectangle(const Rectangle& orig) {
	side_a = orig.side_a;
	side_b = orig.side_b;
	typ = 1;
	//std::cout << "Rectangle successfuly copied" << std::endl;
}

Rectangle& Rectangle::operator=(const Rectangle& right) {
	if (this == &right) return *this;
	//std::cout << "Foursquare copied" << std::endl;
	this->side_a = right.side_a;
	this->side_b = right.side_b;
	return *this;
}

Rectangle operator+(const Rectangle& left, const Rectangle& right) {
	return Rectangle(left.side_a + right.side_a, left.side_b + right.side_b);
}

std::ostream& operator<<(std::ostream& os, const Rectangle& obj) {
	os << "Type of figure: Rectangle\nSides = " << obj.side_a << ", " << obj.side_b << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, Rectangle& obj) {
	obj = Rectangle(is);
	return is;
}

double Rectangle::Square() const {
	return side_a * side_b;
}

size_t Rectangle::Type() const {
	return this->typ;
}

std::ostream& Rectangle::Print(std::ostream& os) const {
	os << *this;
	return os;
}

std::istream& Rectangle::Scan(std::istream& is) {
	is >> *this;
	return is;
}

Rectangle::~Rectangle() {
	//std::cout << "Rectangle deleted" << std::endl;
}