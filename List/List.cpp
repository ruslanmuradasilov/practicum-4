#include "List.h"
#pragma warning(disable : 4996)

// Возврашает явно указатель на элемент, на который указывает итератор в данный момент.
// Неявно возвращает размер данных
void* List::ListIterator::getElement(size_t &size) {
	if (current != NULL) {
		size = current->dataSize;
		return current->data;
	}
	else { // если ни на что не указывает
		size = NULL;
		return NULL;
	}
}

// Возвращает true, если есть следующий элемент, иначе false.
bool List::ListIterator::hasNext() {
	if (current == NULL) // если ни на что не указывает
		return false;
	if (current->nextPointer == NULL) // если указывает на последний элемент списка
		return false;
	else
		return true;
}

// Переход к следующему элементу.
void List::ListIterator::goToNext() {
	if (current != NULL) // если следующий элемент есть
		current = current->nextPointer;
}

// Проверка на равенство итераторов
bool List::ListIterator::equals(Iterator* right) {
	return current == ((ListIterator*)right)->current;
}

// Функция возвращает значение, равное количеству элементов в контейнере.
int List::size() {
	return sizeOfList;
	/*int counter = 0;
	if (head == NULL) // если элементов нет
		return 0;
	Node* temp; // временный узел для проверки количества элементов
	temp = head; // встаём в начало списка
	while (temp != NULL) { // проходим список от начала до конца
		counter++;
		temp = temp->nextPointer;
	}
	return counter;*/
}

// Функция возвращает значение, равное максимальной вместимости контейнера в байтах.
size_t List::max_bytes() {
	return maxSpace;
}

// Функция возвращает указатель на итератор, указывающий на первый найденный
// в контейнере элемент. Если элемент не найден, возвращается пустой указатель.
Container::Iterator* List::find(void *elem, size_t size) {
	if (this->empty()) {
		ListIterator* iterator = (ListIterator*)newIterator();
		return iterator;
	}
	Node* temp;
	temp = head;
	while (temp != NULL) {
		if (memcmp(elem, temp->data, size) == 0) // если блоки памяти равны
			break;
		temp = temp->nextPointer;
	}
	if (temp == NULL) { // если соответствующий элемент не найден
		return new ListIterator(this, NULL);
	}
	ListIterator* iterator = (ListIterator*)newIterator();
	iterator->current = temp;
	return iterator;
}

// Создание итератора, соответствующего данному типу контейнера.
Container::Iterator* List::newIterator() {
	return new ListIterator(this, head);
}

// Функция возвращает указатель на итератор, указывающий на первый элемент
// контейнера. Если контейнер пустой, возвращается нулевой указатель.
Container::Iterator* List::begin() {
	ListIterator* iterator = (ListIterator*)newIterator();
	return iterator;
}

// Функция возвращает указатель на итератор, указывающий позицию за последним
// элементом контейнера. Если контейнер пустой, возвращается нулевой указатель.
Container::Iterator* List::end() {
	ListIterator* iterator = (ListIterator*)newIterator();
	if (!empty()) {
		while (iterator->hasNext())
			iterator->goToNext();
		iterator->goToNext();
	}
	return iterator;
}

// Удаление элемента из позиции, на которую указывает итератор iter.
// После удаления итератор указывает на следующий за удаленным элемент.
void List::remove(Iterator *iter) {
	if (empty())
		return;

	ListIterator* iterator = (ListIterator*)(iter);
	if (iterator->current == NULL)
		return;

	if (iterator->current == head) { // если нужно удалить первый элемент
		head = iterator->current->nextPointer; // второй элемент делаем первым
		freeSpace += sizeof(Node) + iterator->current->dataSize;
		my_memory->freeMem(iterator->current); // освобождаем память
		iterator->current = head; // теперь итератор указывает на новый первый элемент
		sizeOfList--;
		return;
	} 
	else {
		Node* temp;
		temp = head;
		while (temp->nextPointer != iterator->current) // пока не найдём элемент, следующий за которым нужно удалить
			temp = temp->nextPointer;
		temp->nextPointer = iterator->current->nextPointer; // следующим становится элемент через один
		freeSpace += sizeof(Node) + iterator->current->dataSize;
		my_memory->freeMem(iterator->current);
		iterator->current = temp->nextPointer; // теперь итератор указывает на элемент через один
		sizeOfList--;
		return;
	}
}

// Удаление всех элементов из контейнера.
void List::clear() {
	while (!empty())
		pop_front();
	return;
}

// Если контейнер пуст возвращает true, иначе false
bool List::empty() {
	if (size() == 0)
		return true;
	else
		return false;
}

Node* List::init(void* srcptr, size_t size, Node* pointer) {
	if (sizeof(Node) + size <= freeSpace) {
		Node* newNode = (Node*)my_memory->allocMem(sizeof(Node)); // память для узла
		if (newNode == NULL)
			return NULL;
		newNode->data = (void*)my_memory->allocMem(size); // память для data
		newNode->dataSize = size;
		newNode->nextPointer = pointer;
		memcpy(newNode->data, srcptr, size); // куда, откуда, сколько байт
		freeSpace -= (sizeof(Node) + size);
		return newNode;
	}
	else
		return NULL;
}

// Добавление элемента в начало контейнера.
// В случае успешного добавления функция возвращает значение 0, в случае неудачи 1.
int List::push_front(void *elem, size_t elemSize) {
	Node* newNode = init(elem, elemSize, head); // указывает на первый элемент, даже если тот NULL
	if (newNode == NULL)
		return 1;
	head = newNode; // новый элемент становится первым
	sizeOfList++;
	return 0;
}

// Удаление элемента из начала контейнера.
void List::pop_front() {
	if (empty())
		return;
	else if (head != NULL && head->nextPointer == NULL) { // в списке один элемент
		freeSpace += sizeof(Node) + head->dataSize;
		my_memory->freeMem(head);
		head = NULL;
		sizeOfList--;
		return;
	}
	else {
		Node* temp;
		temp = head; // запоминаем начало списка
		head = head->nextPointer; // сдвигаем начало списка к следующему элементу
		freeSpace += sizeof(Node) + temp->dataSize;
		my_memory->freeMem(temp); // освобождаем память, которую занимал head до сдвига
		sizeOfList--;
		return;
	}
}

// Функция явно возвращает указатель на элемент, находящийся в начале контейнера.
// и не явно возвращает размер данных
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

// Добавление элемента в позицию, на которую указывает итератор iter.
// В случае успешного добавления функция возвращает значение 0, в случае неудачи 1.
int List::insert(Iterator *iter, void *elem, size_t elemSize) {
	ListIterator* iterator = (ListIterator*)iter;

	if (empty() && iterator->current == NULL) { // если список пуст
		head = init(elem, elemSize, NULL);
		if (head == NULL)
			return 1;
		iterator->current = head;
		sizeOfList++;
		return 0;
	}

	if (head == iterator->current) { // если итератор указывает на начало списка
		if (push_front(elem, elemSize) == 1)
			return 1;
		iterator->current = head;
		return 0;
	}

	Node* temp;
	temp = head;
	while (temp->nextPointer != iterator->current) // пока не найдём элемент перед элементом, на который указывает итератор
		temp = temp->nextPointer;

	Node* newNode = init(elem, elemSize, NULL); // создаём новый элемент
	temp->nextPointer = newNode; // следующим после temp становится новый узел
	newNode->nextPointer = iterator->current; // следующим за новым узлом становится элемент, на который указывает итератор
	//iterator->current = newNode; // итератор теперь указывает на новый узел (никто не требует этого, без этого список быстрый)
	sizeOfList++;
	return 0;
}