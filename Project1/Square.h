#idndef SQUARE_H_INCLUDED
#define SQUARE_H_INCLUDED
#include <cstdlib>
#include <iostream>

#include "Figure.h"

class Square : public Figure {
public:
	Square();
	Square(std::istream &is);
	Square(size_t a);
	Square(const Square& orig);

	double Square() override;
	void Print() override;

	virtual Square();
private:
	size_t side;
};

#endif