#include <iostream>

#include "TTreeNode.h"

TTreeNode::TTreeNode(const FourSquare& Foursquare) {
	this->Foursquare = Foursquare;
	this->left = nullptr;
	this->right = nullptr;
	std::cout << "Tree node: created" << std::endl;
}

TTreeNode::TTreeNode(const TTreeNode& orig) {
	this->Foursquare = orig.Foursquare;
	this->left = orig.left;
	this->right = orig.right;
	std::cout << "Tree node: copied" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const TTreeNode& obj) {
	os << "[" << obj.Foursquare << "]" << std::endl;
	return os;
}

bool operator>(const TTreeNode& left, const TTreeNode& right) {
	return left.GetFourSquare() > right.GetFourSquare();
}

void TTreeNode::SetLeft(TTreeNode* left) {
	this->left = left;
}

void TTreeNode::SetRight(TTreeNode* right) {
	this->right = right;
}

TTreeNode* TTreeNode::GetLeft() {
	return this->left;
}

TTreeNode* TTreeNode::GetRight() {
	return this->right;
}

FourSquare TTreeNode::GetFourSquare() const {
	return this->Foursquare;
}

TTreeNode::~TTreeNode() {
	std::cout << "Tree node: deleted" << std::endl;
	delete left;
	delete right;
}