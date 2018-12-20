#ifndef TTREE_H_INCLUDED
#define	TTREE_H_INCLUDED

#include <iostream>
#include <memory>

#include "TIterator.h"
#include "TTreeNode.h"

class TTree {
public:
    TTree() {
        this->Root = nullptr;
    }

    void Insert (std::shared_ptr<MyFigure> new_elem) {
    	std::shared_ptr<TTreeNode> father = std::shared_ptr<TTreeNode>(nullptr);
        std::shared_ptr<TTreeNode> curr = this->Root;

        while (curr != nullptr)	{
            curr->GetValue()->Insert(new_elem);
            if (curr->GetValue()->GetSize() <= 5) return;
            new_elem = curr->GetValue()->Pop();
            father = curr;
            if (curr->GetValue()->Top() < new_elem) {
                if (!curr->RightIns()) curr = curr->GetRight();
                else curr = nullptr;
            } else if (curr->GetValue()->Find(new_elem) != nullptr) {
                std::cout << "Already in tree" << std::endl;
                return;
            } else {
                if (!curr->LeftIns()) curr = curr->GetLeft();
                else curr = nullptr;
            }
        }

        curr = std::shared_ptr<TTreeNode>(new TTreeNode(new_elem));
        if (this->Root == nullptr) {
            this->Root = curr;
            this->Root->InsRight();
            this->Root->InsLeft();
        } else if (father->GetValue()->GetSize() < 5) {
            father->GetValue()->Insert(new_elem);
        } else if (father->GetValue()->Top() > new_elem) {
            father->UnInsLeft();
            curr->InsLeft();
            curr->SetLeft(father->GetLeft());
            father->SetLeft(curr);
            curr->InsRight();
            curr->SetRight(father);
        } else {
            curr->InsRight();
            curr->SetRight(father->GetRight());
            father->SetRight(curr);
            curr->InsLeft();
            curr->SetLeft(father);
        }
        std::cout << "Inserted" << std::endl;
        return;
    }

    void Delete (std::shared_ptr<MyFigure> del_elem) {
        std::shared_ptr<TTreeNode> curr = this->Root;
        std::shared_ptr<TTreeNode> father = nullptr;
        while (curr != nullptr && curr->GetValue()->Find(del_elem) == nullptr){
            father = curr;
            if (curr->GetValue()->Top() < del_elem) curr = !curr->RightIns() ? curr->GetRight() : nullptr;
            else if (curr->GetValue()->Find(del_elem) != nullptr) break;
            else curr = !curr->LeftIns() ? curr->GetLeft() : nullptr;
        }

        if (curr == nullptr) {
            std::cout << "Not in tree" << std::endl;
            return;
        }


        curr->GetValue()->Delete(del_elem);
        if (!curr->GetValue()->Empty()) return;

        if (!curr->LeftIns() && !curr->RightIns()) {
            if (curr == this->Root) this->Root = nullptr;
            else if (father->GetRight() == curr) {
                father->SetRight(curr->GetRight());
                father->InsRight();
            } else {
                father->SetLeft(curr->GetLeft());
                father->InsLeft();
            }
            return;
        }

        if (!curr->RightIns()) {
            if (father == nullptr) this->Root = curr->GetLeft();
            else if (father->GetValue()->Top() > del_elem) father->SetLeft(curr->GetLeft());
            else father->SetRight(curr->GetLeft());
            curr->SetLeft(nullptr);
            curr = nullptr;
            return;
        }

        if (!curr->LeftIns()) {
            if (father == nullptr) this->Root = curr->GetRight();
            else if (father->GetValue()->Top() > del_elem) father->SetLeft(curr->GetRight());
            else father->SetRight(curr->GetRight());
            curr->SetRight(nullptr);
            curr = nullptr;
            return;
        }

        std::shared_ptr<TTreeNode> currd = curr->GetRight();
        std::shared_ptr<TTreeNode> prev = curr;
        while (currd->GetLeft() != nullptr) {
            prev = currd;
            currd = currd->GetLeft();
        }

        curr->SetValue(currd->GetValue());
        if (prev == curr) curr->SetRight(currd->GetRight());
        else prev->SetLeft(currd->GetRight());
        currd->SetRight(nullptr);
        currd = nullptr;
        return;
    }

    friend std::ostream& operator<<(std::ostream& os, const TTree& obj) {
        if (obj.Root == nullptr) {
            std::cout << "Tree is empty" << std::endl;
            return os;
        }
        os << *obj.Root;
        return os;
    }

    ~TTree() {
        this->Root = nullptr;
    }

private:
    std::shared_ptr<TTreeNode> Root;
};

#endif
