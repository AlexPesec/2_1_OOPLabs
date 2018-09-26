#ifndef TRAPEZE_H_INCLUDED
#define TRAPEZE_H_INCLUDED

#include <cstdlib>
#include <iostream>

#include "Figure.h"

class Trapeze : public Figure {
public:
	Trapeze();
	Trapeze(std::istream &is);
	Trapeze(size_t a, size_t b, size_t c, size_t d, size_t h);
	Trapeze(const Trapeze& orig);

	double Square() override;
	void Print() override;

	virtual ~Trapeze();
private:
	size_t basis_a;
	size_t basis_b;
	size_t side_a;
	size_t side_b;
	size_t height;
};

#endif