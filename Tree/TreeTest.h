#pragma once

#include <time.h>

/* Ниже подключается соответствующий контейнер: */

//#include "List.h"
//#include "Set.h"
//#include "Queue.h"
//#include "List2.h"
#include "MyTree.h"
//#include "Table.h"

class Test {
public:
	double insert(Tree &mytree, int n)
	{
		Tree tree = mytree;
		size_t size = sizeof(int);
		Tree::TreeIterator* iterator = (Tree::TreeIterator*)tree.newIterator();
		int i;
		int* val = (int*)malloc(n * size);
		int** addr = (int**)malloc(n * sizeof(int*));

		for (i = 0; i < n; i++)
		{
			val[i] = i;
			addr[i] = &(val[i]);
		}

		clock_t start = clock();

		for (i = 0; i < n; i++)
			tree.insert(iterator, val[i], addr[i], size);
		cout << "Size of Tree: " << tree.size() << endl;

		clock_t end = clock();

		for (i = 0; i < n; i++)
		{
			iterator = (Tree::TreeIterator*)tree.find(addr[i], size);
			if (iterator->equalsNull() == true)
				cout << "Inserting is incorrect!" << endl;
			if ((int*)iterator->getElement(size) != addr[i])
				cout << "Inserting is incorrect!!" << endl;
		}

		return (double)(end - start) / CLOCKS_PER_SEC;
	}

	double remove(Tree &mytree, int n)
	{
		Tree tree = mytree;
		size_t size = sizeof(int);
		Tree::TreeIterator* iterator = (Tree::TreeIterator*)tree.newIterator();
		int i;
		int* val = (int*)malloc(n * size);
		int** addr = (int**)malloc(n * sizeof(int*));

		for (i = 0; i < n; i++)
		{
			val[i] = i;
			addr[i] = &(val[i]);
		}

		for (i = 0; i < n; i++)
			tree.insert(iterator, val[i], addr[i], size);
		cout << "Size of Tree: " << tree.size() << endl;
		iterator = (Tree::TreeIterator*)tree.newIterator();

		clock_t start = clock();

		for (i = 0; i < n; i++)
		{
			tree.remove(iterator, 1);
			iterator->goToNext();
		}
		cout << "Size of Tree: " << tree.size() << endl;

		clock_t end = clock();

		for (i = 1; i < n; i++)
		{
			iterator = (Tree::TreeIterator*)tree.find(addr[i], 4);
			if (iterator->equalsNull() == false)
				cout << "Removing is incorrect!" << endl;
			if ((int*)iterator->getElement(size) != NULL)
				cout << "Removing is incorrect!!" << endl;
		}

		return (double)(end - start) / CLOCKS_PER_SEC;
	}

	double find(Tree &mytree, int n)
	{
		Tree tree = mytree;
		size_t size = sizeof(int);
		Tree::TreeIterator* iterator = (Tree::TreeIterator*)tree.newIterator();
		int i;
		int* val = (int*)malloc(n * size);
		int** addr = (int**)malloc(n * sizeof(int*));

		for (i = 0; i < n; i++) {
			val[i] = i;
			addr[i] = &(val[i]);
		}

		for (i = 0; i < n; i++)
			tree.insert(iterator, val[i], addr[i], size);
		cout << "Size of Tree: " << tree.size() << endl;

		clock_t start = clock();

		for (int i = 0; i < n; i++)
		{
			iterator = (Tree::TreeIterator*)tree.find(addr[i], size);
			if ((int*)iterator->getElement(size) != addr[i])
			{
				cout << "Something wrong" << endl;
				return -1;
			}
		}
		cout << "I found all of them!" << endl;

		clock_t end = clock();
		return (double)(end - start) / CLOCKS_PER_SEC;
	}

	/*double find(Tree &mytree, int n)
	{
		Tree tree = mytree;
		size_t size = sizeof(int);
		Tree::TreeIterator* iterator = (Tree::TreeIterator*)tree.newIterator();
		int i;
		int* val = (int*)malloc(n * size);
		int** addr = (int**)malloc(n * sizeof(int*));

		for (i = 0; i < n; i++) {
			val[i] = i;
			addr[i] = &(val[i]);
		}

		for (i = 0; i < n; i++)
			tree.insert(iterator, val[i], addr[i], size);
		cout << "Size of Tree: " << tree.size() << endl;

		clock_t start = clock();

		for (i = 0; i < n; i++) {
			iterator = (Tree::TreeIterator*)tree.find(addr[i], size);
			if (iterator->equalsNull() == true)
				cout << "Finding is incorrect!" << endl;
			if ((int*)iterator->getElement(size) != addr[i])
				cout << "Finding is incorrect!!" << endl;
		}

		clock_t end = clock();
		return (double)(end - start) / CLOCKS_PER_SEC;
	}*/

	double clear(Tree &mytree, int n)
	{
		Tree tree = mytree;
		size_t size = sizeof(int);
		Tree::TreeIterator* iterator = (Tree::TreeIterator*)tree.newIterator();
		int i;
		int* val = (int*)malloc(n * size);
		int** addr = (int**)malloc(n * sizeof(int*));

		for (i = 0; i < n; i++)
		{
			val[i] = i;
			addr[i] = &(val[i]);
		}

		for (i = 0; i < n; i++)
			tree.insert(iterator, val[i], addr[i], size);
		cout << "Size of Tree: " << tree.size() << endl;

		clock_t start = clock();

		tree.clear();

		clock_t end = clock();

		cout << "Size of Tree: " << tree.size() << endl;

		for (i = 0; i < n; i++)
		{
			iterator = (Tree::TreeIterator*)tree.find(addr[i], size);
			if (iterator->equalsNull() == false)
				cout << "Clearing is incorrect!" << endl;
			if ((int*)iterator->getElement(size) != NULL)
				cout << "Clearing is incorrect!!" << endl;
		}
		return (double)(end - start) / CLOCKS_PER_SEC;
	}

	//double removeEven(Tree &mytree, int n)
	//{
	//	Tree tree = mytree;
	//	size_t size = sizeof(int);
	//	Tree::TreeIterator* iterator = (Tree::TreeIterator*)tree.newIterator();
	//	int i;
	//	int* val = (int*)malloc(n * size);
	//	int** addr = (int**)malloc(n * sizeof(int*));

	//	for (i = 0; i < n; i++)
	//	{
	//		val[i] = i;
	//		addr[i] = &(val[i]);
	//	}

	//	for (i = 0; i < n; i++)
	//		tree.insert(iterator, val[i], addr[i], size);
	//	cout << "Size of Tree: " << tree.size() << endl;

	//	clock_t start = clock();
	//	//clock_t start1 = clock();
	//	iterator = (Tree::TreeIterator*)tree.newIterator();
	//	for (i = 0; i < n; i++)
	//	{
	//		if (i % 2 != 0)
	//			tree.remove(iterator, 1);
	//		iterator->goToNext();
	//		/*if (i % 10000 == 0 && i != 0)
	//		{
	//			cout << "Removing..." << endl;
	//			clock_t end1 = clock();
	//			double seconds = (double)(end1 - start1) / CLOCKS_PER_SEC;
	//			cout << "Time: " << seconds << endl;
	//			start1 = clock();
	//		}*/
	//	}
	//	cout << "Size of Tree: " << tree.size() << endl;

	//	clock_t end = clock();

	//	for (i = 1; i < n; i++)
	//	{
	//		iterator = (Tree::TreeIterator*)tree.find(addr[i], size);
	//		if (i % 2 == 0 && iterator->equalsNull() == true)
	//			cout << "Removing (even) is incorrect!" << endl;
	//		if (i % 2 == 1 && iterator->equalsNull() == false)
	//			cout << "Removing (even) is incorrect!!" << endl;
	//	}

	//	return (double)(end - start) / CLOCKS_PER_SEC;
	//}

	double removeEven(Tree &mytree, int n)
	{
		Tree tree = mytree;
		size_t size = sizeof(int);
		Tree::TreeIterator* iterator = (Tree::TreeIterator*)tree.newIterator();
		int i;
		int* val = (int*)malloc(n * size);
		int** addr = (int**)malloc(n * sizeof(int*));

		for (i = 0; i < n; i++)
		{
			val[i] = i;
			addr[i] = &(val[i]);
		}

		for (i = 0; i < n; i++)
			tree.insert(iterator, val[i], addr[i], size);
		cout << "Size of Tree: " << tree.size() << endl;
		iterator = (Tree::TreeIterator*)tree.newIterator();

		clock_t start = clock();

		for (i = 0; i < n; i++)
			if (i % 2 == 1)
			{
				iterator = (Tree::TreeIterator*)tree.find(addr[i], size);
				tree.remove(iterator, 1);
			}
		cout << "Size of Tree: " << tree.size() << endl;

		clock_t end = clock();

		for (i = 1; i < n; i++)
		{
			iterator = (Tree::TreeIterator*)tree.find(addr[i], size);
			if (i % 2 == 0 && iterator->equalsNull() == true)
				cout << "Removing (even) is incorrect!" << endl;
			if (i % 2 == 1 && iterator->equalsNull() == false)
				cout << "Removing (even) is incorrect!!" << endl;
		}

		return (double)(end - start) / CLOCKS_PER_SEC;
	}
};




//class Test {
//public:
//	double insert(Tree &myTree, int n) {
//		Tree tree = myTree;
//		size_t size = sizeof(int);
//		Tree::TreeIterator* iterator = (Tree::TreeIterator*)tree.newIterator();
//
//		clock_t start = clock();
//
//		for (int i = 0; i < n; i++)
//			tree.insert(iterator, i, &i, size);
//		cout << "Size of Tree: " << tree.size() << endl;
//
//		clock_t end = clock();
//		return (double)(end - start) / CLOCKS_PER_SEC;
//	}
//
//	double removeEven(Tree &myTree, int n) {
//		Tree tree = myTree;
//		size_t size = sizeof(int);
//		Tree::TreeIterator* iterator = (Tree::TreeIterator*)tree.newIterator();
//
//		for (int i = 0; i < n; i++)
//			tree.insert(iterator, i, &i, size);
//		cout << "Size of Tree: " << tree.size() << endl;
//
//		clock_t start = clock();
//		//clock_t start1 = clock();
//		iterator = (Tree::TreeIterator*)tree.newIterator();
//		for (int i = 0; i < n; i++) {
//			if (i % 2 != 0)
//				tree.remove(iterator, 1);
//			else
//				iterator->goToNext();
//			/*if (i % 10000 == 0 && i != 0)
//			{
//				cout << "Removing..." << endl;
//				clock_t end1 = clock();
//				double seconds = (double)(end1 - start1) / CLOCKS_PER_SEC;
//				cout << "Time: " << seconds << endl;
//				start1 = clock();
//			}*/
//		}
//		cout << "Size of Tree: " << tree.size() << endl;
//
//		clock_t end = clock();
//		return (double)(end - start) / CLOCKS_PER_SEC;
//	}
//
//	double find(Tree &myTree, int n) {
//		Tree tree = myTree;
//		size_t size = sizeof(int);
//		Tree::TreeIterator* iterator = (Tree::TreeIterator*)tree.newIterator();
//		int** p_value = (int**)malloc(n*size);
//
//		for (int i = 0; i < n; i++)
//		{
//			p_value[i] = &i;
//			tree.insert(iterator, i, p_value[i], size);
//		}
//
//		cout << "Size of Tree: " << tree.size() << endl;
//
//		clock_t start = clock();
//
//		for (int i = 0; i < n; i++)
//		{
//			iterator = (Tree::TreeIterator*)tree.find(p_value[i], size);
//			if ((int*)iterator->getElement(size) != p_value[i])
//			{
//				cout << "Something wrong" << endl;
//				return -1;
//			}
//		}
//		cout << "I found all of them!" << endl;
//
//		clock_t end = clock();
//		return (double)(end - start) / CLOCKS_PER_SEC;
//	}
//
//	double clear(Tree &myTree, int n) {
//		Tree tree = myTree;
//		size_t size = sizeof(int);
//		Tree::TreeIterator* iterator = (Tree::TreeIterator*)tree.newIterator();
//
//		for (int i = 0; i < n; i++)
//			tree.insert(iterator, i, &i, size);
//		cout << "Size of Tree: " << tree.size() << endl;
//
//		clock_t start = clock();
//
//		tree.clear();
//		cout << "Size of Tree: " << tree.size() << endl;
//
//		clock_t end = clock();
//		return (double)(end - start) / CLOCKS_PER_SEC;
//	}
//};