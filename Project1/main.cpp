#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <memory>

#include "TIterator.h"
#include "Figure.h"
#include "TStack.h"
#include "TTree.h"

#include "FourSquare.h"
#include "Rectangle.h"
#include "Trapeze.h"

void Help() {
	std::cout << "To print tree enter:                  p" << std::endl;
	std::cout << "To add figure to tree enter:          a [name_of_figure] [side]" << std::endl;
	std::cout << "To delete figure from tree enter:     d [name_of_figure] [side]" << std::endl;
	std::cout << "To exit programm enter:               e" << std::endl;
	std::cout << "To see this messege again enter:      h\n" << std::endl;
	std::cout << "Names of figures:\ns - square\nr - rectangle\nt - trapeze\n" << std::endl;
}

class Lambda {
public:
    explicit Lambda (size_t & _a): a(_a) {}
    size_t operator () () {
        a = rand();
        return a;
    }
private:
    size_t a;
};

int main() {
    std::shared_ptr<TStack<MyFigure>> T = std::shared_ptr<TStack<MyFigure>>(new TStack<MyFigure>());
	std::shared_ptr<MyFigure> ptr;
    char ch;

    Help();

	while (true) {
		std::cin >> ch;
		if (ch == 'e') {
			break;
		} else if (ch == 'a') {
			std::cin >> ch;
			if (ch == 's') ptr = std::shared_ptr<MyFigure>(new MyFigure(new FourSquare(std::cin)));
			else if (ch == 'r') ptr = std::shared_ptr<MyFigure>(new MyFigure(new Rectangle(std::cin)));
			else if (ch == 't') ptr = std::shared_ptr<MyFigure>(new MyFigure(new Trapeze(std::cin)));
			else {
				std::cout << "Wrong figure" << std::endl;
				continue;
			}
			T->Insert(ptr);
		} else if (ch == 'd') {
			std::cin >> ch;
			if (ch == 's') ptr = std::shared_ptr<MyFigure>(new MyFigure(new FourSquare(std::cin)));
			else if (ch == 'r') ptr = std::shared_ptr<MyFigure>(new MyFigure(new Rectangle(std::cin)));
			else if (ch == 't') ptr = std::shared_ptr<MyFigure>(new MyFigure(new Trapeze(std::cin)));
			else {
				std::cout << "Wrong figure" << std::endl;
				continue;
			}
			T->Delete(ptr);
        } else if (ch == 'r') {
            T = std::shared_ptr<TStack<MyFigure>>(new TStack<MyFigure>());
            int a;
            std::cin >> a;

            std::vector<size_t> V (a);

            std::for_each(V.begin(), V.end(), [](size_t _n) {_n = rand();});

            for (int i = 0; i < a; ++i) std::cout << V[i] << ' ';
/*
            for (int i = 0; i < a; ++i)
                T->Insert(std::shared_ptr<MyFigure>(new MyFigure(new FourSquare(V[i]))));
*/
		} else if (ch == 'p') {
            std::for_each(T->begin(), T->end(), [](std::shared_ptr<MyFigure> _F) {std::cout << *_F;});
		} else if (ch == 'l') {
		    double a;
		    std::cin >> a;
		    std::for_each(T->begin(), T->end(), [T, a](std::shared_ptr<MyFigure> _F) {if (_F->Square() < a) T->Delete(_F);});
		} else if (ch == 'h') {
			Help();
		} else {
			continue;
		}
	}

	T = nullptr;
    return 0;
}
