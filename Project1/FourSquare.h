#ifndef SQUARE_H_INCLUDED
#define SQUARE_H_INCLUDED

#include <cstdlib>
#include <iostream>

#include "Figure.h"

class FourSquare : public Figure {
public:
	FourSquare();
	FourSquare(std::istream &is);
	FourSquare(size_t a);
	FourSquare(const FourSquare& orig);

	double Square() override;
	void Print() override;

	virtual ~FourSquare();
private:
	size_t side;
};

#endif