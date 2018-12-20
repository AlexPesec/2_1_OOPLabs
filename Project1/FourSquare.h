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

	FourSquare& operator=(const FourSquare& right);
	friend FourSquare operator+(const FourSquare& left, const FourSquare& right);

	friend std::ostream& operator<<(std::ostream& os, const FourSquare& obj);
	friend std::istream& operator>>(std::istream& is, FourSquare& obj);

	size_t Type() const override;
	double Square() const override;
	std::ostream& Print(std::ostream& os) const override;
	std::istream& Scan(std::istream& is) override;

	virtual ~FourSquare();
private:
	size_t side;
	size_t typ;
};

#endif