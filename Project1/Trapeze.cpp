#include <iostream>
#include <cmath>

#include "Trapeze.h"

Trapeze::Trapeze() : Trapeze(0, 0, 0, 0) {}

Trapeze::Trapeze(size_t a, size_t b, size_t c, size_t d) :
	basis_a(a), basis_b(b), side_a(c), side_b(d) {
	std::cout << "Trapeze created: " << basis_a << ", " << basis_b << ", " << side_a << ", " << side_b << std::endl;
}

Trapeze::Trapeze(std::istream& is) {
	is >> basis_a;
	is >> basis_b;
	is >> side_a;
	is >> side_b;
	std::cout << "Trapeze successfuly read" << std::endl;
}

Trapeze::Trapeze(const Trapeze& orig) {
	basis_a = orig.basis_a;
	basis_b = orig.basis_b;
	side_a = orig.side_a;
	side_b = orig.side_b;
	std::cout << "Trapeze successfuly copied" << std::endl;
}

double Trapeze::Square() {
	double m = basis_a + basis_b;
	double dif = fabs(basis_a - basis_b);
	double curr_sa = (double)side_a;
	double curr_sb = (double)side_b;

	std::cout << m << " " << dif << " " << curr_sa << " " << curr_sb << std::endl;

	return m * sqrt(pow(curr_sa, 2) - pow((dif * dif + pow(curr_sa, 2) - pow(curr_sb, 2)) / (2 * dif), 2)) / 2;
}

void Trapeze::Print() {
	std::cout << "basis: a = " << basis_a << " b = " << basis_b << "\nsides: a = " << side_a << " b = " << side_b << std::endl;
}

Trapeze::~Trapeze() {
	std::cout << "Trapeze deleted" << std::endl;
}