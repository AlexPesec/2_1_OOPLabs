#include <iostream>

#include "TTree.h"

TTree::TTree() {
	this->root = nullptr;
}

TTree::TTree(const TTree& tree) {
	this->root = tree.root;
}

void TTree::add(FourSquare& Foursquare) {
	if (this->root == nullptr) {
	}
}

bool TTree::empty() {
	return this->root == nullptr;
}

void TTree::del(FourSquare& Foursquare) {

}

std::ostream& operator<<(std::ostream& os, const TTree& obj) {
	if (obj.root == nullptr) return os;
	os << obj.root->GetLeft() << std::endl;
	os << obj.root->GetFourSquare() << std::endl;
	os << obj.root->GetRight() << std::endl;
}

TTree::~TTree() {

}