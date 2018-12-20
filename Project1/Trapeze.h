#ifndef TRAPEZE_H_INCLUDED
#define TRAPEZE_H_INCLUDED

#include <cstdlib>
#include <iostream>

#include "Figure.h"

class Trapeze : public Figure {
public:
	Trapeze();
	Trapeze(std::istream &is);
	Trapeze(size_t a, size_t b, size_t h);
	Trapeze(const Trapeze& orig);

	Trapeze& operator=(const Trapeze& right);
	friend Trapeze operator+(const Trapeze& left, const Trapeze& right);

	friend std::ostream& operator<<(std::ostream& os, const Trapeze& obj);
	friend std::istream& operator>>(std::istream& is, Trapeze& obj);

	double Square() const override;
	size_t Type() const override;
	std::ostream& Print(std::ostream& os) const override;
	std::istream& Scan(std::istream& is) override;

	virtual ~Trapeze();
private:
	size_t basis_a;
	size_t basis_b;
	size_t height;
	size_t typ;
};

#endif