#pragma once
#include "List.h"
#include "ListTest.h"
#include "Mem.h"
#include <time.h>

#define N 1000000

using namespace std;

int main() {
	Mem mem(16 * N);
	Test test;
	List lst(mem);

	cout << test.insert(lst, N) << endl << endl;
	cout << test.remove(lst, N) << endl << endl;
	//cout << test.find(lst, N) << endl << endl;
	cout << test.clear(lst, N) << endl << endl;

	system("pause");
	return 0;
}














//int main() {
//	Mem mem(16 * N);
//	List lst(mem);
//
//	int i, counter = 0;
//	size_t size;
//	List::ListIterator* iterator = (List::ListIterator*)lst.newIterator();
//	List::ListIterator* iterator_2;
//	
//	int values[N] = { 0 };
//	int* addresses[N] = { 0 };
//	
//	for (i = 0; i < N; i++) {
//		values[i] = i;
//		addresses[i] = &(values[i]);
//	}
//	
//	/************************************************************/
//	// Добавление N элементов
//	
//	clock_t start = clock();
//	
//	for (i = 0; i < N; i++) {
//		lst.insert(iterator, addresses[i], sizeof(int));
//		if (*(int*)iterator->getElement(size) == i)
//			counter++;
//		iterator->goToNext();
//	}
//	if (counter == N)
//		cout << "SUCCESS" << endl;
//	else
//		cout << "ERROR" << endl;
//	cout << "Size of list: " << lst.size() << endl;
//	clock_t end = clock();
//	double seconds = (double)(end - start) / CLOCKS_PER_SEC;
//	cout << "Time: " << seconds << endl << endl << endl;
//	
//	/************************************************************/
//	// Удаление всех нечётных
//	
//	start = clock();
//	counter = 0;
//	for (i = 0; i < N; i++) {
//		if (i % 2 != 0) {
//			iterator = (List::ListIterator*)lst.find(addresses[i], sizeof(int));
//			lst.remove(iterator);
//		}
//	}
//	for (iterator = (List::ListIterator*)lst.begin(),
//		iterator_2 = (List::ListIterator*)lst.end();
//		iterator->equals(iterator_2) == false;
//		iterator->goToNext()) {
//		if (*(int*)iterator->getElement(size) % 2 == 0)
//			counter++;
//	}
//	if (counter == N/2 || counter == N/2 + 1)
//		cout << "SUCCESS" << endl;
//	else
//		cout << "ERROR" << endl;
//	cout << "Size of list: " << lst.size() << endl;
//	end = clock();
//	seconds = (double)(end - start) / CLOCKS_PER_SEC;
//	cout << "Time: " << seconds << endl << endl << endl;
//	
//	/************************************************************/
//	// Очистка списка
//	
//	start = clock();
//	lst.clear();
//	if (lst.size() == 0)
//		cout << "CLEARED" << endl;
//	cout << "Size of list: " << lst.size() << endl;
//	end = clock();
//	seconds = (double)(end - start) / CLOCKS_PER_SEC;
//	cout << "Time: " << seconds << endl << endl << endl;
//	
//	/************************************************************/
//	
//	system("pause");
//	return 0;
//}









	/**************************************************************************************************************/
//	size_t size = 0;
//
//	int values[20] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
//	int* addresses[20] = { 0 };
//	int i;
//	for (i = 0; i < 20; i++) {
//		addresses[i] = &(values[i]);
//	}
//	i = 0;
//
//	cout << "lst.max_bytes(): " << lst.max_bytes() << endl;
//	cout << "lst.size() ___ lst.freeSpace: " << lst.size() << " " << lst.freeSpace << endl << endl;
//
//	/*List::ListIterator* iterator = (List::ListIterator*)lst.newIterator();
//	lst.insert(iterator, addresses, sizeof(int));
//	cout << "lst.size() ___ lst.freeSpace: " << lst.size() << " " << lst.freeSpace << endl;*/
//
//	/*lst.push_front(addresses, 72*sizeof(int));
//	cout << "PUSH_FRONT => lst.size() ___ lst.freeSpace: " << lst.size() << " " << lst.freeSpace << endl;*/
//
//	lst.push_front(addresses[i], sizeof(int));
//	i++;
//	cout << "PUSH_FRONT => lst.size() ___ lst.freeSpace: " << lst.size() << " " << lst.freeSpace << endl;
//
//	List::ListIterator* iterator = (List::ListIterator*)lst.begin();
//	cout << "begin() => hasNext? (1 - true, 0 - false): " << iterator->hasNext() << endl << endl;
//
//
//	lst.insert(iterator, addresses[i], sizeof(int));
//	i++;
//	cout << "INSERT => lst.size() ___ lst.freeSpace: " << lst.size() << " " << lst.freeSpace << endl;
//	cout << "hasNext? (1 - true, 0 - false): " << iterator->hasNext() << endl << endl;
//
//
//
//
//	iterator = (List::ListIterator*)lst.find(addresses[0], sizeof(int));
//	cout << "find() => hasNext? (1 - true, 0 - false): " << iterator->hasNext() << endl << endl;
//
//	iterator = (List::ListIterator*)lst.find(addresses[1], sizeof(int));
//	cout << "find() => hasNext? (1 - true, 0 - false): " << iterator->hasNext() << endl << endl;
//
//
//
//
//
//	lst.remove(iterator);
//	cout << "REMOVE => lst.size() ___ lst.freeSpace: " << lst.size() << " " << lst.freeSpace << endl;
//	cout << "hasNext? (1 - true, 0 - false): " << iterator->hasNext() << endl << endl;
//
//
//
//	lst.insert(iterator, addresses[i], sizeof(int));
//	i++;
//	cout << "INSERT => lst.size() ___ lst.freeSpace: " << lst.size() << " " << lst.freeSpace << endl;
//	cout << "hasNext? (1 - true, 0 - false): " << iterator->hasNext() << endl << endl;
//
//
//
//	lst.insert(iterator, addresses[i], sizeof(int));
//	i++;
//	cout << "INSERT => lst.size() ___ lst.freeSpace: " << lst.size() << " " << lst.freeSpace << endl;
//	cout << "hasNext? (1 - true, 0 - false): " << iterator->hasNext() << endl << endl;
//
//
//
//	lst.insert(iterator, addresses[i], sizeof(int));
//	i++;
//	cout << "INSERT => lst.size() ___ lst.freeSpace: " << lst.size() << " " << lst.freeSpace << endl;
//	cout << "hasNext? (1 - true, 0 - false): " << iterator->hasNext() << endl << endl;
//
//
//	cout << "iterator->getElement(size): " << iterator->getElement(size) << endl << endl;
//
//	lst.front(size);
//	cout << "front(size) => size: " << size << endl << endl;
//
//
//	/*lst.pop_front();
//
//	lst.insert(iterator, addresses[i], sizeof(int));
//	i++;
//	cout << "lst.size() ___ lst.freeSpace: " << lst.size() << " " << lst.freeSpace << endl;
//	cout << "hasNext? (1 - true, 0 - false): " << iterator->hasNext() << endl << endl;*/
//
//
//	/*iterator = (List::ListIterator*)lst.end();
//	cout << "end() => hasNext? (1 - true, 0 - false): " << iterator->hasNext() << endl << endl;*/
//
//
//	lst.remove(iterator);
//	cout << "REMOVE => lst.size() ___ lst.freeSpace: " << lst.size() << " " << lst.freeSpace << endl;
//	cout << "hasNext? (1 - true, 0 - false): " << iterator->hasNext() << endl << endl;
//
//	lst.remove(iterator);
//	cout << "REMOVE => lst.size() ___ lst.freeSpace: " << lst.size() << " " << lst.freeSpace << endl;
//	cout << "hasNext? (1 - true, 0 - false): " << iterator->hasNext() << endl << endl;
//
//	lst.remove(iterator);
//	cout << "REMOVE => lst.size() ___ lst.freeSpace: " << lst.size() << " " << lst.freeSpace << endl;
//	cout << "hasNext? (1 - true, 0 - false): " << iterator->hasNext() << endl << endl;
//
//	lst.remove(iterator);
//	cout << "REMOVE => lst.size() ___ lst.freeSpace: " << lst.size() << " " << lst.freeSpace << endl;
//	cout << "hasNext? (1 - true, 0 - false): " << iterator->hasNext() << endl << endl;
//
//	lst.remove(iterator);
//	cout << "REMOVE => lst.size() ___ lst.freeSpace: " << lst.size() << " " << lst.freeSpace << endl;
//	cout << "hasNext? (1 - true, 0 - false): " << iterator->hasNext() << endl << endl;
//
//
//
//
//	iterator = (List::ListIterator*)lst.find(addresses[2], sizeof(int));
//	cout << "find() => hasNext? (1 - true, 0 - false): " << iterator->hasNext() << endl << endl;
//
//
//
//
//	lst.insert(iterator, addresses[i], sizeof(int));
//	i++;
//	cout << "INSERT => lst.size() ___ lst.freeSpace: " << lst.size() << " " << lst.freeSpace << endl;
//	cout << "hasNext? (1 - true, 0 - false): " << iterator->hasNext() << endl << endl;
//
//
//
//
//
//	iterator->goToNext();
//	cout << "iterator->goToNext();" << endl << endl;
//
//
//	lst.remove(iterator);
//	cout << "REMOVE => lst.size() ___ lst.freeSpace: " << lst.size() << " " << lst.freeSpace << endl;
//	cout << "hasNext? (1 - true, 0 - false): " << iterator->hasNext() << endl << endl;
//
//
//
//	lst.pop_front();
//	cout << "POP_FRONT => lst.size() ___ lst.freeSpace: " << lst.size() << " " << lst.freeSpace << endl;
//	cout << "hasNext? (1 - true, 0 - false): " << iterator->hasNext() << endl << endl;
//
//
//
//
//	cout << "SIZEOFLIST: " << lst.sizeOfList << endl << endl;
//	lst.front(size);
//	cout << "front(size) => size: " << size << endl << endl;
//
//	lst.insert(iterator, addresses[i], sizeof(int));
//	i++;
//	cout << "INSERT => lst.size() ___ lst.freeSpace: " << lst.size() << " " << lst.freeSpace << endl;
//	cout << "hasNext? (1 - true, 0 - false): " << iterator->hasNext() << endl << endl;
//
//	lst.insert(iterator, addresses[i], sizeof(int));
//	i++;
//	cout << "INSERT => lst.size() ___ lst.freeSpace: " << lst.size() << " " << lst.freeSpace << endl;
//	cout << "hasNext? (1 - true, 0 - false): " << iterator->hasNext() << endl << endl;
//
//
//	iterator->goToNext();
//	cout << "iterator->goToNext();" << endl << endl;
//	cout << "lst.size() ___ lst.freeSpace: " << lst.size() << " " << lst.freeSpace << endl;
//	cout << "hasNext? (1 - true, 0 - false): " << iterator->hasNext() << endl << endl;
//
//
//
//	iterator = (List::ListIterator*)lst.end();
//	cout << "end() => hasNext? (1 - true, 0 - false): " << iterator->hasNext() << endl << endl;
//
//	/*cout << "iterator->getElement(size): " << *(int*)iterator->getElement(size) << endl << endl;*/
//
//
//
//	lst.remove(iterator); // ремув NULL'a => ничего не удалилось, всё верно
//	cout << "REMOVE => lst.size() ___ lst.freeSpace: " << lst.size() << " " << lst.freeSpace << endl;
//	cout << "hasNext? (1 - true, 0 - false): " << iterator->hasNext() << endl << endl;
//
//
//
//	lst.insert(iterator, addresses[i], sizeof(int));
//	i++;
//	cout << "INSERT => lst.size() ___ lst.freeSpace: " << lst.size() << " " << lst.freeSpace << endl;
//	cout << "hasNext? (1 - true, 0 - false): " << iterator->hasNext() << endl << endl;
//
//
//
//	iterator = (List::ListIterator*)lst.begin();
//	cout << "begin() => hasNext should be 1" << endl;
//	cout << "lst.size() ___ lst.freeSpace: " << lst.size() << " " << lst.freeSpace << endl;
//	cout << "hasNext? (1 - true, 0 - false): " << iterator->hasNext() << endl << endl;
//
//
//
//
//
//
//
//	lst.clear();
//	i = 0;
//	size = 0;
//	cout << "clear() => lst.size() ___ lst.freeSpace: " << lst.size() << " " << lst.freeSpace << endl;
//	system("pause");
//	return 0;
//}