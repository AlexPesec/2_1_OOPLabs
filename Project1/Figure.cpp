#include <iostream>

#include "Figure.h"

std::ostream& operator<<(std::ostream& os, std::shared_ptr<Figure> Fig) {
	return Fig->Print(os);
}

std::istream& operator>>(std::istream& is, std::shared_ptr<Figure> Fig) {
	return Fig->Scan(is);
}
