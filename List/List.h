#pragma once
#include "ListAbstract.h"
#include "Mem.h"

struct Node {
	void* data;
	size_t dataSize;
	Node* nextPointer;
};

class List : public AbstractList {
protected:
	Node* head;
	Mem* my_memory;

public:
	List(Mem &mem) : AbstractList(mem) {
		head = NULL;
		sizeOfList = 0;
		my_memory = &mem;
		maxSpace = mem.size();
		freeSpace = mem.size();
	}
	~List() {
		clear();
		maxSpace = 0;
		freeSpace = 0;
		my_memory = NULL;
	}

	class ListIterator : public Iterator {
	public:
		Node* current;
		List* list;
		ListIterator(List* list, Node* head) : list(list), current(head) {}
		~ListIterator() {}

		void* getElement(size_t &size);
		bool hasNext();
		void goToNext();
		bool equals(Iterator *right);
	};

	size_t maxSpace;
	size_t freeSpace;
	int sizeOfList;

	int size();
	size_t max_bytes();
	Iterator* find(void *elem, size_t size);
	Iterator* newIterator();
	Iterator* begin();
	Iterator* end();
	void remove(Iterator *iter);
	void clear();
	bool empty();

	Node* init(void* srcptr, size_t size, Node* pointer);

	int push_front(void *elem, size_t elemSize);
	void pop_front();
	void* front(size_t &size);
	int insert(Iterator *iter, void *elem, size_t elemSize);
};