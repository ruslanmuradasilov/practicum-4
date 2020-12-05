#pragma once
#include "MyTree.h"
#include "TreeTest.h"
#include "Mem.h"
#include <time.h>

#define N 1e3

using namespace std;

int main()
{
	Mem mem(10 * N);
	Test test;
	Tree myTree(mem);

	cout << test.insert(myTree, N) << endl << endl;//1e6 - 3 sec, 1e7 - 34 sec (с проверкой тестить на 1e3)
	cout << test.remove(myTree, N) << endl << endl;//1e5 - 2 sec, 1e6 - 196 sec (с проверкой тестить на 1e5)
	cout << test.find(myTree, N) << endl << endl;//1e3 - 0.9 sec, 1e4 - 74 sec
	cout << test.clear(myTree, N) << endl << endl;//1e6 - 3 sec, 1e7 - 37 sec (с проверкой тестить на 1e6)
	cout << test.removeEven(myTree, N) << endl << endl;//1e3 - 0.5 sec, 1e4 - 38 sec (с проверкой тестить на 1e3)

	system("pause");
	return 0;
}


//int main()
//{
//    Mem mem(10 * N);
//    Tree myTree(mem);
//
//	int value[N], index = 0, count = 1;
//	int* p_value[N] = {0};
//	for (int i = 0; i < N; i++)
//	{
//		value[i] = i;
//		p_value[i] = &(value[i]);
//	}
//
//	
//	size_t size;
//	//Tree::TreeIterator* it = (Tree::TreeIterator*)myTree.begin();
//	Tree::Iterator* it = myTree.begin();
//	Tree::Iterator* it1 = myTree.end();
//
//	clock_t start = clock();
//
//	myTree.insert(it, index, p_value[index], sizeof(int));
//	for (index = 1; index < N; index++)
//	{
//		myTree.insert(it, index, p_value[index], sizeof(int));
//		it->goToChild(index);
//		if ( (*(int*)it->getElement(size)) == index)
//			count++;
//		it->goToParent();
//	}
//	if (count == N)
//		cout << "Success" << endl;
//	else
//		cout << "Error" << endl;
//	cout << "Tree size = " << myTree.size() << endl;
//	clock_t end = clock();
//	double seconds = (double)(end - start) / CLOCKS_PER_SEC;
//	cout << "Time: " << seconds << endl;
//
//	cout << endl;
//
//	start = clock();
//	count = 0;
//	clock_t start1 = clock();
//	for (int i = 0; i < N; i++)
//	{
//		if (i % 2 != 0)
//		{
//			it = myTree.find(p_value[i], sizeof(int));
//			myTree.remove(it, 1);
//		}
//		if (i % 1000 == 0 && i != 0)
//		{
//			cout << "Removing..." << endl;
//			clock_t end1 = clock();
//			seconds = (double)(end1 - start1) / CLOCKS_PER_SEC;
//			cout << "Time: " << seconds << endl;
//			start1 = clock();
//		}
//	}
//	for (it = myTree.begin(), it1 = myTree.end(); it->equals(it1) == false; it->goToNext())
//	{
//		if ((*(int*)it->getElement(size)) % 2 == 0)
//			count++;
//	}
//	if (count == N/2 - 1)
//		cout << "Success" << endl;
//	else
//		cout << "Error" << endl;
//	cout << "Tree size = " << myTree.size() << endl;
//	end = clock();
//	seconds = (double)(end - start) / CLOCKS_PER_SEC;
//	cout << "Time: " << seconds << endl;
//
//	cout << endl;
//
//	start = clock();
//	myTree.clear();
//	if (myTree.size() == 0)
//		cout << "Cleared" << endl;
//	cout << "Tree size = " << myTree.size() << endl;
//	end = clock();
//	seconds = (double)(end - start) / CLOCKS_PER_SEC;
//	cout << "Time: " << seconds << endl;
//
//	cout << endl;
//
// /*******************************************************************/
///*
//    int value, value2, index = 1;
//    int* p_value = &value;
//    int* p_value2 = &value2;
//    size_t size;
//    //Tree::TreeIterator* it = (Tree::TreeIterator*)myTree.begin();
//    Tree::Iterator* it = myTree.begin();
//    Tree::Iterator* it1 = myTree.end();
//
//    cin >> value >> value2;
//    myTree.insert(it, index, p_value, sizeof(int));
//    index++;
//    myTree.insert(it, index, p_value2, sizeof(int));
//    cout << "Tree size = " << myTree.size() << endl;
//    it->goToNext();
//    //it->goToChild(index);
//    //it->goToParent();
//    cout << (*(int*)it->getElement(size)) << endl;
//
//    /*****Экзотика*****/
///*    myTree.remove(it, 1);
//    myTree.insert(it, index, p_value2, sizeof(int));
//    cout << "Tree size = " << myTree.size() << endl;
//
//	it = myTree.find(p_value2, sizeof(int));
//	cout << (*(int*)it->getElement(size)) << endl;
//
//    myTree.remove(it, 1);
//    it = myTree.end();
//	cout << "Tree size = " << myTree.size() << endl;
//    cout << (*(int*)it->getElement(size)) << endl;
//
//    for (it = myTree.begin(), it1 = myTree.end(); it->equals(it1) == false; it->goToNext())
//      cout << (*(int*)it->getElement(size)) << endl;
//  */  
//    system("pause");
//    return 0;
//}