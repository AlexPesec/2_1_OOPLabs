#ifndef TTREENODE_H_INCLUDED
#define	TTREENODE_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <memory>

#include "TIterator.h"
#include "Figure.h"
#include "TStack.h"

class TTreeNode {
public:
    TTreeNode() {
        this->Value = nullptr;
        this->Right = nullptr;
        this->Left = nullptr;
        this->LeftIn = false;
        this->RightIn = false;
    }

    TTreeNode(std::shared_ptr<MyFigure> value) {
        std::shared_ptr<TStack<MyFigure>> new_val = std::shared_ptr<TStack<MyFigure>> (new TStack<MyFigure>(value));
        this->Value = new_val;
        this->Right = nullptr;
        this->Left = nullptr;
        this->LeftIn = false;
        this->RightIn = false;
    }

    std::shared_ptr<TStack<MyFigure>> GetValue() {return this->Value;}
    void SetValue(std::shared_ptr<TStack<MyFigure>> new_val) {this->Value = new_val;}

    std::shared_ptr<TTreeNode> GetRight() {return this->RightIn ? this->Right : nullptr;}
    std::shared_ptr<TTreeNode> GetNext() {return this->Right;}
    void SetRight(std::shared_ptr<TTreeNode> new_right) {this->Right = new_right;}
    bool RightIns() {return this->RightIn;}
    void InsRight() {this->RightIn = true;}
    void UnInsRight() {this->RightIn = false;}

    std::shared_ptr<TTreeNode> GetLeft() {return this->LeftIn ? this->Left : nullptr;}
    std::shared_ptr<TTreeNode> GetPrev() {return this->Left;}
    void SetLeft(std::shared_ptr<TTreeNode> new_left) {this->Left = new_left;}
    bool LeftIns() {return this->LeftIn;}
    void InsLeft() {this->LeftIn = true;}
    void UnInsLeft() {this->LeftIn = false;}

    friend std::ostream& operator<<(std::ostream& os, const TTreeNode& obj) {
        if (!obj.LeftIn) os << *obj.Left;
        os << *obj.Value;
        if (!obj.RightIn) os << *obj.Right;
        return os;
    }

    ~TTreeNode () {
        this->Value = nullptr;
        this->Right = nullptr;
        this->Left = nullptr;
    }

private:
    std::shared_ptr<TStack<MyFigure>> Value;
    std::shared_ptr<TTreeNode> Right;
    std::shared_ptr<TTreeNode> Left;

    bool LeftIn;
    bool RightIn;
};

#endif
