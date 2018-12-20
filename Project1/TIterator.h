#ifndef TITERATOR_H_INCLUDED
#define TITERATOR_H_INCLUDED

#include <iostream>
#include <memory>

template <class TNode, class T>
class TIterator {
public:
	TIterator(std::shared_ptr<TNode> n) {
		node_ptr = n;
	}

	std::shared_ptr<T> operator* () {
		return node_ptr->GetValue();
	}

	std::shared_ptr<T> operator-> () {
		return node_ptr->GetValue();
	}

	void operator++ () {
		node_ptr = node_ptr->GetNext();
	}

	TIterator operator++ (int) {
		TIterator iter(*this);
		++(*this);
		return iter;
	}

	bool operator== (TIterator const& i) {
		return node_ptr == i.node_ptr;
	}

	bool operator!= (TIterator const& i) {
		return !(*this == i);
	}

private:
	std::shared_ptr <TNode> node_ptr;
};

#endif
