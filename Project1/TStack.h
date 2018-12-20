#ifndef TSTACK_H_INCLUDED
#define TSTACK_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <memory>

#include "TIterator.h"

#include "TStackItem.h"
#include "Figure.h"

template <class T>
class TStack {
public:
    TStack () {
        this->Head = nullptr;
        this->Size = 0;
    }

    TStack (std::shared_ptr<T> new_elem) {
        std::shared_ptr<TStackItem<T>> new_item = std::shared_ptr<TStackItem<T>>(new TStackItem<T>(new_elem));
        this->Head = new_item;
        this->Size = 1;
    }

    TStack (const TStack& orig) {
        this->Head = orig.Head;
        this->Size = orig.Size;
    }

    TIterator<TStackItem<T>, T> begin() {
        return TIterator<TStackItem<T>, T>(Head);
    }

    TIterator<TStackItem<T>, T> end() {
        return TIterator<TStackItem<T>, T>(nullptr);
    }


    size_t GetSize() {
        return this->Size;
    }

    void Push (std::shared_ptr<T>& new_elem) {
     	std::shared_ptr<TStackItem<T>> new_item = std::shared_ptr<TStackItem<T>>(new TStackItem<T>(new_elem));
        new_item->SetNext(this->Head);
        this->Head = new_item;
        this->Size++;
    }

    bool Insert (std::shared_ptr<T>& new_elem) {
        std::shared_ptr<TStackItem<T>> new_item = std::shared_ptr<TStackItem<T>>(new TStackItem<T> (new_elem));
        if (this->Head == nullptr) {
            this->Head = new_item;
            this->Size++;
            return true;
        }

        std::shared_ptr<TStackItem<T>> curr = this->Head;

        if (new_item->GetValue() > curr->GetValue()) {
            new_item->SetNext(this->Head);
            this->Head = new_item;
            this->Size++;
            return true;
        }

        if (new_item->GetValue() == curr->GetValue()) {
            return false;
        }

        while (curr->GetNext() != nullptr && new_item->GetValue() > curr->GetNext()->GetValue()) {
            if (new_item->GetValue() == curr->GetNext()->GetValue()) return false;
            curr = curr->GetNext();
        }

        curr->Insert(new_item);
        this->Size++;
        return true;
    }

    bool Delete (std::shared_ptr<T> del_elem) {
        std::shared_ptr <TStackItem<T>> curr = this->Head;

        if (this->Head->GetValue() == del_elem) {
            this->Head->SetValue(nullptr);
            this->Head = this->Head->GetNext();
            curr->SetNext(nullptr);
            curr = nullptr;
            this->Size--;
            return true;
        }

        while (curr->GetNext() != nullptr && curr->GetNext()->GetValue() > del_elem)
            curr = curr->GetNext();

        if (curr->GetNext() == nullptr || curr->GetNext()->GetValue() < del_elem)
            return false;

        curr->SetNext(curr->GetNext()->GetNext());
        this->Size--;
        return true;
    }

    bool Empty () {
        return this->Head == nullptr;
    }

    std::shared_ptr<T> Pop () {
        std::shared_ptr<T> result = std::shared_ptr<T>(nullptr);
        if (this->Head != nullptr) {
            std::shared_ptr<TStackItem<T>> old_head = this->Head;
            this->Head = this->Head->GetNext();
            result = old_head->GetValue();
            old_head->SetNext(nullptr);
            old_head = nullptr;
        }
        this->Size--;
        return result;
    }

    std::shared_ptr<MyFigure> Top () {
        return this->Head->GetValue();
    }

    std::shared_ptr<T> Find(std::shared_ptr<T> s_elem) {
        std::shared_ptr<TStackItem<T>> curr = this->Head;

        while (curr != nullptr){
            if (curr->GetValue() == s_elem) return curr->GetValue();
            curr = curr->GetNext();
        }

        return nullptr;
    }

    bool operator< (std::shared_ptr<TStack>& rhs) {
        if (this->Size < rhs->Size) return true;
        if (this->Size > rhs->Size) return false;
        std::shared_ptr<TStackItem<T>> curr_l = this->Head;
        std::shared_ptr<TStackItem<T>> curr_r = rhs->Head;

        while (curr_l != nullptr) {
            if (curr_l->GetValue() < curr_r->GetValue()) return true;
            if (curr_l->GetValue() > curr_r->GetValue()) return false;
        }

        return false;
    }

    friend std::ostream& operator<<(std::ostream& os, const TStack& obj) {
        if (obj.Head != nullptr) os << *obj.Head;
        return os;
    }

    virtual ~TStack () {
        this->Head = nullptr;
    }

private:
    std::shared_ptr<TStackItem<T>> Head;
    size_t Size;
};

#endif
