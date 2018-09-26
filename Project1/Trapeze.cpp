#include <iostream>
#include <cmath>

#include "Trapeze.h"

Trapeze::Trapeze() : Trapeze(0, 0, 0, 0, 0) {}

Trapeze::Trapeze(size_t a, size_t b, size_t c, size_t d, size_t h) :
	basis_a(a), basis_b(b), side_a(c), side_b(d), height(h) {
	std::cout << "Trapeze created: " << basis_a << ", " << basis_b << ", " << side_a << ", " << side_b << ", " << height << std::endl;
}

Trapeze::Trapeze(std::istream& is) {
	is >> basis_a;
	is >> basis_b;
	is >> side_a;
	is >> side_b;
	is >> height;
	std::cout << "Trapeze successfuly read" << std::endl;
}

Trapeze::Trapeze(const Trapeze& orig) {
	basis_a = orig.basis_a;
	basis_b = orig.basis_b;
	side_a = orig.side_a;
	side_b = orig.side_b;
	height = orig.height;
	std::cout << "Trapeze successfuly copied" << std::endl;
}

double Trapeze::Square() {
	return (double)(basis_a + basis_b) * height / 2;
}

void Trapeze::Print() {
	std::cout << "basis: a = " << basis_a << " b = " << basis_b << "\nsides: a = " << side_a << " b = " << side_b << "\nheight = " << height << std::endl;
}

Trapeze::~Trapeze() {
	std::cout << "Trapeze deleted" << std::endl;
}