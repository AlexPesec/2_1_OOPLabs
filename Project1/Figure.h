#ifndef FIGURE_H_INCLUDED
#define	FIGURE_H_INCLUDED

#include <iostream>
#include <memory>

class Figure {
public:
	virtual double Square() const = 0;
	virtual size_t Type() const = 0;

	virtual std::ostream& Print(std::ostream& os) const = 0;
	virtual std::istream& Scan(std::istream& is) = 0;

	friend std::ostream& operator<<(std::ostream& os, std::shared_ptr<Figure> Fig);
	friend std::istream& operator>>(std::istream& is, std::shared_ptr<Figure> Fig);

	virtual ~Figure() {};
};

class MyFigure {
public:
    std::shared_ptr<Figure> Fig;

    MyFigure() {
        this->Fig = nullptr;
    }

    MyFigure (Figure* fig) {
        this->Fig = std::shared_ptr<Figure> (fig);
    }

    bool operator> (MyFigure& rhs) {
        if (this->Fig->Type() != rhs.Fig->Type()) return this->Fig->Type() > rhs.Fig->Type();
        return rhs.Fig->Square() > this->Fig->Square();
    }

    bool operator== (MyFigure& rhs) {
        return this->Fig->Type() == rhs.Fig->Type() && rhs.Fig->Square() == this->Fig->Square();
    }

    bool operator< (MyFigure& rhs) {
        if (this->Fig->Type() != rhs.Fig->Type()) return this->Fig->Type() < rhs.Fig->Type();
        return rhs.Fig->Square() < this->Fig->Square();
    }

    friend std::ostream& operator<< (std::ostream& os, MyFigure& MFig) {
        os << MFig.Fig;
        return os;
    }

    friend std::istream& operator>> (std::istream& is, MyFigure& MFig) {
        is >> MFig.Fig;
        return is;
    }

    double Square() {
        return this->Fig->Square();
    }

    virtual ~MyFigure () {
        this->Fig = nullptr;
    }
};

#endif
