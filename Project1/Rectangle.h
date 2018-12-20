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

	Rectangle& operator=(const Rectangle& right);
	friend Rectangle operator+(const Rectangle& left, const Rectangle& right);

	friend std::ostream& operator<<(std::ostream& os, const Rectangle& obj);
	friend std::istream& operator>>(std::istream& is, Rectangle& obj);

	double Square() const override;
	size_t Type() const override;
	std::ostream& Print(std::ostream& os) const override;
	std::istream& Scan(std::istream& is) override;

	virtual ~Rectangle();
private:
	size_t side_a;
	size_t side_b;
	size_t typ;
};

#endif