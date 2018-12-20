#ifndef TALLOCATIONBLOCK_H_INCLUDED
#define TALLOCATIONBLOCK_H_INCLUDED

#include <cstdlib>

#include "TStack.h"

class TAllocationBlock {
public:
	TAllocationBlock(size_t size, size_t count) {
		_used_blocks = (char*)malloc(_size * _count);
		_free_blocks = new TStack();

		for (size_t i = 0; i < _count; ++i) _free_blocks->push(_used_blocks + i * _size);
		_free_count = _count;
		std::cout << "TAllocationBlock: Memory init" << std::endl;
	}

	void *allocate() {
		void *result = nullptr;

		if (_free_count > 0) {
			result = _free_blocks->pop();
			_free_count--;
			std::cout << "TAllocationBlock: Allocate " << (_count - _free_count) << " of " << _count << std::endl;
		}
		else {
			std::cout << "TAllocationBlock: No memory exception" << std::endl;
		}

		return result;
	}

	void deallocate(void *pointer) {
		std::cout << "TAllocationBlock: Deallocate block " << std::endl;
		_free_blocks->push(pointer);
		_free_count++;
	}

	bool has_free_blocks() {
		return _free_count > 0;
	}

	~TAllocationBlock() {
		if (_free_count < _count) std::cout << "TAllocationBlock: Memory leak?" << std::endl;
		else  std::cout << "TAllocationBlock: Memory freed" << std::endl;
		delete _free_blocks;
	}
private:
	size_t _size;
	size_t _count;

	char  *_used_blocks;
	TStack* _free_blocks;

	size_t _free_count;
};


#endif