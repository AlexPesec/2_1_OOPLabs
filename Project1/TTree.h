#ifndef TTREE_H_NOT_INCLUDED
#define TTREE_H_NOT_INCLUDED

#include "TTreeNode.h"
#include "FourSquare.h"

class TTree {
public:
	TTree();
	TTree(const TTree& orig);

	void add(FourSquare& Foursquare);
	bool empty();
	void del(FourSquare& Foursquare);
	friend std::ostream& operator<<(std::ostream& os, const TTree& tree);
	
	virtual ~TTree();
private:
	TTreeNode* root;
};


#endif