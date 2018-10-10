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

	friend bool operator==(const FourSquare& left,const FourSquare& right);
	FourSquare& operator=(const FourSquare& right);
	friend FourSquare operator+(const FourSquare& left, const FourSquare& right);

	friend std::ostream& operator<<(std::ostream& os, const FourSquare& obj);
	friend std::istream& operator>>(std::istream& is, FourSquare& obj);

	double Square() override;
	void Print() override;

	virtual ~FourSquare();
private:
	size_t side;
};

#endif