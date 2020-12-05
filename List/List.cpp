#include "List.h"
#pragma warning(disable : 4996)

// ���������� ���� ��������� �� �������, �� ������� ��������� �������� � ������ ������.
// ������ ���������� ������ ������
void* List::ListIterator::getElement(size_t &size) {
	if (current != NULL) {
		size = current->dataSize;
		return current->data;
	}
	else { // ���� �� �� ��� �� ���������
		size = NULL;
		return NULL;
	}
}

// ���������� true, ���� ���� ��������� �������, ����� false.
bool List::ListIterator::hasNext() {
	if (current == NULL) // ���� �� �� ��� �� ���������
		return false;
	if (current->nextPointer == NULL) // ���� ��������� �� ��������� ������� ������
		return false;
	else
		return true;
}

// ������� � ���������� ��������.
void List::ListIterator::goToNext() {
	if (current != NULL) // ���� ��������� ������� ����
		current = current->nextPointer;
}

// �������� �� ��������� ����������
bool List::ListIterator::equals(Iterator* right) {
	return current == ((ListIterator*)right)->current;
}

// ������� ���������� ��������, ������ ���������� ��������� � ����������.
int List::size() {
	return sizeOfList;
	/*int counter = 0;
	if (head == NULL) // ���� ��������� ���
		return 0;
	Node* temp; // ��������� ���� ��� �������� ���������� ���������
	temp = head; // ����� � ������ ������
	while (temp != NULL) { // �������� ������ �� ������ �� �����
		counter++;
		temp = temp->nextPointer;
	}
	return counter;*/
}

// ������� ���������� ��������, ������ ������������ ����������� ���������� � ������.
size_t List::max_bytes() {
	return maxSpace;
}

// ������� ���������� ��������� �� ��������, ����������� �� ������ ���������
// � ���������� �������. ���� ������� �� ������, ������������ ������ ���������.
Container::Iterator* List::find(void *elem, size_t size) {
	if (this->empty()) {
		ListIterator* iterator = (ListIterator*)newIterator();
		return iterator;
	}
	Node* temp;
	temp = head;
	while (temp != NULL) {
		if (memcmp(elem, temp->data, size) == 0) // ���� ����� ������ �����
			break;
		temp = temp->nextPointer;
	}
	if (temp == NULL) { // ���� ��������������� ������� �� ������
		return new ListIterator(this, NULL);
	}
	ListIterator* iterator = (ListIterator*)newIterator();
	iterator->current = temp;
	return iterator;
}

// �������� ���������, ���������������� ������� ���� ����������.
Container::Iterator* List::newIterator() {
	return new ListIterator(this, head);
}

// ������� ���������� ��������� �� ��������, ����������� �� ������ �������
// ����������. ���� ��������� ������, ������������ ������� ���������.
Container::Iterator* List::begin() {
	ListIterator* iterator = (ListIterator*)newIterator();
	return iterator;
}

// ������� ���������� ��������� �� ��������, ����������� ������� �� ���������
// ��������� ����������. ���� ��������� ������, ������������ ������� ���������.
Container::Iterator* List::end() {
	ListIterator* iterator = (ListIterator*)newIterator();
	if (!empty()) {
		while (iterator->hasNext())
			iterator->goToNext();
		iterator->goToNext();
	}
	return iterator;
}

// �������� �������� �� �������, �� ������� ��������� �������� iter.
// ����� �������� �������� ��������� �� ��������� �� ��������� �������.
void List::remove(Iterator *iter) {
	if (empty())
		return;

	ListIterator* iterator = (ListIterator*)(iter);
	if (iterator->current == NULL)
		return;

	if (iterator->current == head) { // ���� ����� ������� ������ �������
		head = iterator->current->nextPointer; // ������ ������� ������ ������
		freeSpace += sizeof(Node) + iterator->current->dataSize;
		my_memory->freeMem(iterator->current); // ����������� ������
		iterator->current = head; // ������ �������� ��������� �� ����� ������ �������
		sizeOfList--;
		return;
	} 
	else {
		Node* temp;
		temp = head;
		while (temp->nextPointer != iterator->current) // ���� �� ����� �������, ��������� �� ������� ����� �������
			temp = temp->nextPointer;
		temp->nextPointer = iterator->current->nextPointer; // ��������� ���������� ������� ����� ����
		freeSpace += sizeof(Node) + iterator->current->dataSize;
		my_memory->freeMem(iterator->current);
		iterator->current = temp->nextPointer; // ������ �������� ��������� �� ������� ����� ����
		sizeOfList--;
		return;
	}
}

// �������� ���� ��������� �� ����������.
void List::clear() {
	while (!empty())
		pop_front();
	return;
}

// ���� ��������� ���� ���������� true, ����� false
bool List::empty() {
	if (size() == 0)
		return true;
	else
		return false;
}

Node* List::init(void* srcptr, size_t size, Node* pointer) {
	if (sizeof(Node) + size <= freeSpace) {
		Node* newNode = (Node*)my_memory->allocMem(sizeof(Node)); // ������ ��� ����
		if (newNode == NULL)
			return NULL;
		newNode->data = (void*)my_memory->allocMem(size); // ������ ��� data
		newNode->dataSize = size;
		newNode->nextPointer = pointer;
		memcpy(newNode->data, srcptr, size); // ����, ������, ������� ����
		freeSpace -= (sizeof(Node) + size);
		return newNode;
	}
	else
		return NULL;
}

// ���������� �������� � ������ ����������.
// � ������ ��������� ���������� ������� ���������� �������� 0, � ������ ������� 1.
int List::push_front(void *elem, size_t elemSize) {
	Node* newNode = init(elem, elemSize, head); // ��������� �� ������ �������, ���� ���� ��� NULL
	if (newNode == NULL)
		return 1;
	head = newNode; // ����� ������� ���������� ������
	sizeOfList++;
	return 0;
}

// �������� �������� �� ������ ����������.
void List::pop_front() {
	if (empty())
		return;
	else if (head != NULL && head->nextPointer == NULL) { // � ������ ���� �������
		freeSpace += sizeof(Node) + head->dataSize;
		my_memory->freeMem(head);
		head = NULL;
		sizeOfList--;
		return;
	}
	else {
		Node* temp;
		temp = head; // ���������� ������ ������
		head = head->nextPointer; // �������� ������ ������ � ���������� ��������
		freeSpace += sizeof(Node) + temp->dataSize;
		my_memory->freeMem(temp); // ����������� ������, ������� ������� head �� ������
		sizeOfList--;
		return;
	}
}

// ������� ���� ���������� ��������� �� �������, ����������� � ������ ����������.
// � �� ���� ���������� ������ ������
void* List::front(size_t &size) {
	if (!empty()) {
		size = head->dataSize;
		return head->data;
	}
	else {
		size = NULL;
		return NULL;
	}
}

// ���������� �������� � �������, �� ������� ��������� �������� iter.
// � ������ ��������� ���������� ������� ���������� �������� 0, � ������ ������� 1.
int List::insert(Iterator *iter, void *elem, size_t elemSize) {
	ListIterator* iterator = (ListIterator*)iter;

	if (empty() && iterator->current == NULL) { // ���� ������ ����
		head = init(elem, elemSize, NULL);
		if (head == NULL)
			return 1;
		iterator->current = head;
		sizeOfList++;
		return 0;
	}

	if (head == iterator->current) { // ���� �������� ��������� �� ������ ������
		if (push_front(elem, elemSize) == 1)
			return 1;
		iterator->current = head;
		return 0;
	}

	Node* temp;
	temp = head;
	while (temp->nextPointer != iterator->current) // ���� �� ����� ������� ����� ���������, �� ������� ��������� ��������
		temp = temp->nextPointer;

	Node* newNode = init(elem, elemSize, NULL); // ������ ����� �������
	temp->nextPointer = newNode; // ��������� ����� temp ���������� ����� ����
	newNode->nextPointer = iterator->current; // ��������� �� ����� ����� ���������� �������, �� ������� ��������� ��������
	//iterator->current = newNode; // �������� ������ ��������� �� ����� ���� (����� �� ������� �����, ��� ����� ������ �������)
	sizeOfList++;
	return 0;
}