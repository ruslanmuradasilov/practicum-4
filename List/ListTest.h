#pragma once

#include <time.h>

/* Ниже подключается соответствующий контейнер: */

#include "List.h"
//#include "Set.h"
//#include "Queue.h"
//#include "List2.h"
//#include "Tree.h"
//#include "Table.h"

class Test {
public:
	double insert(List &mylst, int n) {
		List lst = mylst;
		size_t size = sizeof(int);
		List::ListIterator* iterator = (List::ListIterator*)lst.newIterator();

		clock_t start = clock();

		for (int i = 0; i < n; i++)
			lst.insert(iterator, &i, size);
		cout << "Size of list: " << lst.size() << endl;

		clock_t end = clock();
		return (double)(end - start) / CLOCKS_PER_SEC;
	}

	double remove(List &mylst, int n) {
		List lst = mylst;
		size_t size = sizeof(int);
		List::ListIterator* iterator = (List::ListIterator*)lst.newIterator();

		for (int i = 0; i < n; i++)
			lst.insert(iterator, &i, size);
		cout << "Size of list: " << lst.size() << endl;

		clock_t start = clock();

		iterator = (List::ListIterator*)lst.newIterator();
		for (int i = 0; i < n; i++) {
			//if (i % 2 != 0)
				lst.remove(iterator);
			//else
				//iterator->goToNext();
		}
		cout << "Size of list: " << lst.size() << endl;

		clock_t end = clock();
		return (double)(end - start) / CLOCKS_PER_SEC;
	}

	double find(List &mylst, int n) {
		List lst = mylst;
		size_t size = sizeof(int);
		List::ListIterator* iterator = (List::ListIterator*)lst.newIterator();

		for (int i = 0; i < n; i++)
			lst.insert(iterator, &i, size);
		cout << "Size of list: " << lst.size() << endl;

		clock_t start = clock();

		for (int i = 0; i < n; i++) {
			iterator = (List::ListIterator*)lst.find(&i, size);
			if (*(int*)iterator->getElement(size) != i) {
				cout << "Something wrong" << endl;
				return -1;
			}
		}
		cout << "I found all of them!" << endl;

		clock_t end = clock();
		return (double)(end - start) / CLOCKS_PER_SEC;
	}

	double clear(List &mylst, int n) {
		List lst = mylst;
		size_t size = sizeof(int);
		List::ListIterator* iterator = (List::ListIterator*)lst.newIterator();

		for (int i = 0; i < n; i++)
			lst.insert(iterator, &i, size);
		cout << "Size of list: " << lst.size() << endl;

		clock_t start = clock();

		lst.clear();
		cout << "Size of list: " << lst.size() << endl;

		clock_t end = clock();
		return (double)(end - start) / CLOCKS_PER_SEC;
	}
};
