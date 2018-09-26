#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

#include <cstdlib>
#include <iostream>

#include "Figure.h"

class Rectangle : public Figure {
public:
	Rectangle();
	Rectangle(std::istream &is);
	Rectangle(size_t a, size_t b);
	Rectangle(const Rectangle& orig);

	double Square() override;
	void Print() override;

	virtual ~Rectangle();
private:
	size_t side_a;
	size_t side_b;
};

#endif