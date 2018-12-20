#include <iostream>
#include <cmath>

#include "Trapeze.h"

Trapeze::Trapeze() : Trapeze(0, 0, 0) {}

Trapeze::Trapeze(size_t a, size_t b, size_t h) :
	basis_a(a), basis_b(b), height(h) {
	this->typ = 2;
	//std::cout << "Trapeze created: " << basis_a << ", " << basis_b << ", " << height << std::endl;
}

Trapeze::Trapeze(std::istream& is) {
	is >> basis_a;
	is >> basis_b;
	is >> height;
	typ = 2;
	//std::cout << "Trapeze successfuly read" << std::endl;
}

Trapeze::Trapeze(const Trapeze& orig) {
	basis_a = orig.basis_a;
	basis_b = orig.basis_b;
	height = orig.height;
	typ = 2;
	//std::cout << "Trapeze successfuly copied" << std::endl;
}

Trapeze& Trapeze::operator=(const Trapeze& right) {
	if (this == &right) return *this;
	//std::cout << "Foursquare copied" << std::endl;
	this->basis_a = right.basis_a;
	this->basis_b = right.basis_b;
	this->height = right.height;
	return *this;
}

Trapeze operator+(const Trapeze& left, const Trapeze& right) {
	return Trapeze(left.basis_a + right.basis_a, left.basis_b + right.basis_b, left.height + right.height);
}

std::ostream& operator<<(std::ostream& os, const Trapeze& obj) {
	os << "Type of figure: Trapeze\nBasises: " << obj.basis_a << ", " << obj.basis_b << "\nHeight = " << obj.height << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, Trapeze& obj) {
	obj = Trapeze(is);
	return is;
}

double Trapeze::Square() const {
	return (double)((basis_a + basis_b) * height) / 2.0;
}

size_t Trapeze::Type() const {
	return this->typ;
}

std::ostream& Trapeze::Print(std::ostream& os) const {
	os << *this;
	return os;
}

std::istream& Trapeze::Scan(std::istream& is) {
	is >> *this;
	return is;
}

Trapeze::~Trapeze() {
	std::cout << "Trapeze deleted" << std::endl;
}