#ifndef TSTACKITEM_H_INCLUDED
#define TSTACKITEM_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <memory>

#include "TIterator.h"
#include "Figure.h"

template <class T>
class TStackItem {
public:
    TStackItem () {
        this->Value = nullptr;
        this->Next = nullptr;
    }

    TStackItem (const std::shared_ptr<T>& new_val) {
        this->Value = new_val;
        this->Next = nullptr;
    }

    TStackItem (const std::shared_ptr<TStackItem<T>>& orig) {
        this->Value = orig->Value;
        this->Next = orig->Next;
    }

    void Insert (std::shared_ptr<TStackItem<T>> next) {
        std::shared_ptr<TStackItem<T>> old = this->Next;
        this->Next = next;
        next->Next = old;
        return;
    }

    void SetNext(std::shared_ptr<TStackItem<T>> next) {
        this->Next = next;
    }

    void SetValue(std::shared_ptr<T> new_val) {
        this->Value = new_val;
    }

    std::shared_ptr<TStackItem<T>> GetNext() {
        return this->Next;
    }

    std::shared_ptr<T> GetValue () {
        return this->Value;
    }

    friend std::ostream& operator<<(std::ostream& os, const TStackItem<T>& obj) {
        if (obj.Next != nullptr) os << *obj.Next;
        os << *obj.Value;
        return os;
    }

    virtual ~TStackItem () {
        this->Value = nullptr;
        this->Next = nullptr;
    }

private:
    std::shared_ptr<T> Value;
    std::shared_ptr<TStackItem<T>> Next;
};

#endif
