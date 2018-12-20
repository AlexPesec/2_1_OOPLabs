#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <function>
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

int main() {
    std::shared_ptr<TStack<MyFigure>> T = std::shared_ptr<TStack<MyFigure>>(new TStack<MyFigure>());
	std::shared_ptr<MyFigure> ptr;
    char ch;

    typedef std::function<void (void) > command;
    command cmd_insert = [&]() {
        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution(1, 1000);
 
        for (int i = 0; i < 10; i++) {
            int side = distribution(generator);
            tree_figure.push(new FourSquare(side));
        }
    };

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
            std::for_each(V.begin(), V.end(), [](comand*));
			
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
