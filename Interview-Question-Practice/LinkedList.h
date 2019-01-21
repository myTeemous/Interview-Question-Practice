#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include <iostream>
using namespace std;

template <class T>
class LinkedList {

protected:
	struct Node {

		T _value;
		Node* _next;

		Node(T value, Node* next = NULL):_value(value), _next(next)
		{}
	};

	Node* _head;

	void destroyList();

public:
	LinkedList(Node* head = NULL):_head(head)
	{}
	~LinkedList() { destroyList(); }
	void add(T);
	void remove(T);
	void display() const;
};

#endif
