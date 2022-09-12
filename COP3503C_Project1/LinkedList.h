#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

template <typename T>
class LinkedList {
public: 
	struct Node {
		T data;
		Node* next;
		Node* prev;
		Node();
		Node(T d);
		Node(T d, Node* n);
		Node(T d, Node* n, Node* p);
	};
	//part 1
	//variables
	Node* head; 
	Node* tail; 
	unsigned int count;

	//constructor/destructor
	LinkedList();
	~LinkedList();
	void AddHead(const T& d);
	void AddTail(const T& d);
	void AddNodesHead(const T* d, unsigned int c);
	void AddNodesTail(const T* d, unsigned int c);
	unsigned int NodeCount() const;
	void PrintForward() const;
	void PrintReverse() const;

	//part 2
	Node* Head();
	const Node* Head() const;
	Node* Tail();
	const Node* Tail() const;
	Node* GetNode(unsigned int index);
	const Node* GetNode(unsigned int index) const;
	T& operator[](unsigned int index);
	const T& operator[](unsigned int index) const;
	Node* Find(const T& data);
	const Node* Find(const T& data) const;

	void FindAll(vector<Node*>& outData, const T& value) const;

	LinkedList(const LinkedList<T>& list);
	LinkedList<T>& operator=(const LinkedList<T>& rhs);

	//part 3
	/*InsertBefore
	InsertAfter
	InsertAt
	operator==*/
	void InsertAfter(Node* node, const T& data);
	void InsertBefore(Node* node, const T& data);
	void InsertAt(const T& data, unsigned int index);
	bool operator ==(const LinkedList<T>& rhs) const;

	//part 4
	/*RemoveHead()
	RemoveTail()
	RemoveAt()
	Remove()
	Clear()
	Copy Constructor
	operator=
	PrintForwardRecursive()
	PrintReverseRecursive()*/
	bool RemoveHead();
	bool RemoveTail();
	unsigned int Remove(const T& data);
	bool RemoveAt(unsigned int index);
	void Clear();
	void PrintForwardRecursive(const Node* node) const;
	void PrintReverseRecursive(const Node* node) const;
};

template <typename T>
LinkedList<T>::Node::Node() {
	data = NULL;
	next = nullptr;
	prev = nullptr;
}

template <typename T>
LinkedList<T>::Node::Node(T d) {
	data = d;
	next = nullptr; 
	prev = nullptr;
}

template <typename T>
LinkedList<T>::Node::Node(T d, Node* n) {
	data = d;
	next = n;
	prev = nullptr;
}

template <typename T>
LinkedList<T>::Node::Node(T d, Node* n, Node* p) {
	data = d; 
	next = n;
	prev = p;
}

template <typename T>
LinkedList<T>::LinkedList() {
	count = 0;
	head = nullptr; 
	tail = nullptr; 
}

template <typename T>
LinkedList<T>::~LinkedList() {
	Node* current = head;
	while (current != nullptr) {
		head = current->next; 
		delete current; 
		current = head;
	}
	delete head;
}

template <typename T>
void LinkedList<T>::AddHead(const T& d) {
	Node* newNode = new Node(d);
	if (head == nullptr) {
		head = newNode; 
		tail = newNode; 
	}
	else {
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
	count++;
}

template <typename T>
void LinkedList<T>::AddTail(const T& d) {
	Node* newNode = new Node(d);
	if (head == nullptr) {
		head = newNode; 
		tail = newNode; 
	}
	else {
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
	count++;
}

template<typename T>
void LinkedList<T>::AddNodesHead(const T* d, unsigned int c){
	for (unsigned int i = c-1; i >= 0 && i < c; i--) {
		AddHead(d[i]);
	}
}

template <typename T>
void LinkedList<T>::AddNodesTail(const T* d, unsigned int c) {
	for (unsigned int i = 0; i < c; i++) {
		AddTail(d[i]);
	}
}

template <typename T>
void LinkedList<T>::PrintForward() const {
	Node* current = head;
	while (current != nullptr) {
		cout << current->data << endl;
		current = current->next;
	}
}

template <typename T>
void LinkedList<T>::PrintReverse() const {
	Node* lastOne = tail;
	while (lastOne != nullptr) {
		cout << lastOne->data << endl;
		lastOne = lastOne->prev;
	}
}

template <typename T>
unsigned int LinkedList<T>::NodeCount() const {
	return count;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Head() {
	return head;
}

template <typename T>
const typename LinkedList<T>:: Node* LinkedList<T>::Head() const{
	return head;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Tail() {
	return tail;
}

template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Tail() const {
	return tail;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index) {
	if (index >= count || index < 0) {
		cout << "this works 2" << endl;
		throw std::out_of_range("out of range");
	}
	else {
		Node* temp = head;
		for (unsigned int i = 0; i < index; i++) {
			temp = temp->next;
		}
		return temp;
	}
}

template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index) const {
	if (index >= count || index < 0) {
		cout << "this works 3" << endl;
		throw std::out_of_range("out of range");
	}
	else {
		Node* temp = head;
		for (unsigned int i = 0; i < index; i++) {
			temp = temp->next;
		}
		return temp;
	}
}

template <typename T>
T& LinkedList<T>::operator[](unsigned int index) {
	Node* temp = GetNode(index);
	return temp->data;
}

template <typename T>
const T& LinkedList<T>::operator[](unsigned int index) const {
	Node* temp = GetNode(index);
	return temp->data;
}

template <typename T>
typename LinkedList<T>:: Node* LinkedList<T>::Find(const T& data) {
	Node* current = head; 
	for (unsigned int i = 0; i < count; i++) {
		if (current->data == data) {
			return current;
		}
		current = current->next;
	}
	return nullptr;
}

template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Find(const T& data) const {
	Node* current = head;
	for (unsigned int i = 0; i < count; i++) {
		if (current->data == data) {
			return current;
		}
		current = current->next;
	}
	return nullptr;
}

template <typename T>
void LinkedList<T>::FindAll(vector<Node*>& outData, const T& value) const {
	Node* looking = new Node(value);
	Node* current = head;
	for (unsigned int i = 0; i < count; i++) {
		if (current->data == looking->data) {
			outData.push_back(current);
		}
		current = current->next;
	}
	delete looking;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& list) {
	head = nullptr;
	tail = nullptr;
	count = 0;
	Node* current = list.head;
	for (unsigned int i = 0; i < list.count; i++) {
		AddTail(current->data);
		current = current->next;
	}
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs) {
	Node* current = head;
	while (current != nullptr) {
		head = current->next;
		delete current;
		current = head;
	}
	delete head;
	head = nullptr;
	tail = nullptr;
	count = 0;
	Node* current2 = rhs.head;
	for (unsigned int i = 0; i < rhs.count; i++) {
		AddTail(current2->data);
		current2 = current2->next;
	}
	return *this;
}

template <typename T>
void LinkedList<T>::InsertAfter(Node* node, const T& data) {
	Node* adding = new Node(data);
	Node* current = head;
	while (current != nullptr) {
		if (current == node) {
			adding->prev = current;
			adding->next = current->next;
			current->next->prev = adding;
			current->next = adding;
			count++;
			break;
		}
		current = current->next;
	}
}

template <typename T>
void LinkedList<T>::InsertBefore(Node* node, const T& data) {
	Node* adding = new Node(data);
	Node* current = head;
	while (current != nullptr) {
		if (current == node) {
			adding->next = current; 
			adding->prev = current->prev; 
			current->prev->next = adding;
			current->prev = adding;
			count++;
			break;
		}
		current = current->next;
	}
}

template <typename T>
void LinkedList<T>::InsertAt(const T& data, unsigned int index) {
	if (index > count || index < 0) {
		//cout << "this works" << endl;
		throw std::out_of_range("out of range");
	}
	else {
		if (index == 0) {
			AddHead(data);
		}
		else if (index == count) {
			AddTail(data);
		}
		else {
			InsertBefore(GetNode(index), data);
		}
	} 
}

template <typename T>
bool LinkedList<T>::operator ==(const LinkedList<T>& rhs) const {
	Node* current = head; 
	Node* rhsCurrent = rhs.head;
	while (current != nullptr) {
		if (current->data != rhsCurrent->data) {
			return false; 
		}
		else {
			current = current->next;
			rhsCurrent = rhsCurrent->next; 
		}
	}
	return true; 
}

template <typename T>
bool LinkedList<T>::RemoveHead() {
	if (head == nullptr) {
		return false; 
	}
	else {
		Node* newHead = head->next;
		delete head;
		head = newHead;
		if (head != nullptr) {
			head->prev = nullptr;
		}
		count--;
		if (count == 0) {
			head = nullptr;
			tail = nullptr;
		}
		return true; 
	}
}

template <typename T>
bool LinkedList<T>::RemoveTail() {
	if (tail == nullptr) {
		return false;
	}
	else {
		Node* newTail = tail->prev;
		delete tail;
		tail = newTail;
		if (tail != nullptr) {
			tail->next = nullptr;
		}
		count--;
		if (count == 0) {
			head = nullptr;
			tail = nullptr;
		}
		return true;
	}
}

template <typename T>
unsigned int LinkedList<T>::Remove(const T& data) {
	Node* current = head;
	unsigned int removed = 0;
	while (current != nullptr) {
		Node* temp = current->next;
		if (current->data == data) {
			if (current == head) {
				RemoveHead();
				removed++;
				count--;
			}
			else if (current == tail) {
				RemoveTail();
				removed++;
				count--;
			} 
			else {
				current->next->prev = current->prev;
				current->prev->next = current->next;
				delete current; 
				removed++;
				count--;
			}
		}
		current = temp;
	}
	return removed;
}

template <typename T>
bool LinkedList<T>::RemoveAt(unsigned int index) {

	if (index >= count) {
		return false;
	}
	else {
		Node* current = GetNode(index);
		current->next->prev = current->prev;
		current->prev->next = current->next;
		delete current;
		count--;
		return true;
	}
}

template <typename T>
void LinkedList<T>::Clear() {
	Node* current = head;
	while (current != nullptr) {
		head = current->next;
		delete current;
		current = head;
	}
	head = nullptr;
	tail = nullptr;
	count = 0;
}

template <typename T>
void LinkedList<T>::PrintForwardRecursive(const Node* node) const {
	if (node == nullptr) {
		return;
	}
	cout << node->data << endl;
	PrintForwardRecursive(node->next);
}

template <typename T>
void LinkedList<T>::PrintReverseRecursive(const Node* node) const {
	if (node == nullptr) {
		return;
	}
	cout << node->data << endl;
	PrintReverseRecursive(node->prev);
}
