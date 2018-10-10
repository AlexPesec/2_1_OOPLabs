#ifndef TTREENODE_H_NOT_INCLUDED
#define TTREENODE_H_NOT_INCLUDED

#include "FourSquare.h"

class TTreeNode {
public:
	TTreeNode(const FourSquare& Foursquare);
	TTreeNode(const TTreeNode& orig);
	friend std::ostream& operator<<(std::ostream& os, const TTreeNode& obj);

	friend bool operator>(const TTreeNode& left, const TTreeNode& right);

	void SetLeft(TTreeNode* left);
	void SetRight(TTreeNode* right);

	TTreeNode* GetLeft();
	TTreeNode* GetRight();

	FourSquare GetFourSquare() const;

	virtual ~TTreeNode();
private:
	FourSquare Foursquare;
	TTreeNode* left;
	TTreeNode* right;
};


#endif