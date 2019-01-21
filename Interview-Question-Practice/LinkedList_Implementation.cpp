#include <iostream>

#include "LinkedList.h"
using namespace std;

template <class T>
void LinkedList<T>::add(T value)
{
	if (_head == NULL)
		_head = new Node(value, _head);
	else
	{
		Node* nodePtr = _head;

		while (nodePtr->_next != NULL)
		{
			nodePtr = nodePtr->_next;
		}

		nodePtr->_next = new Node(value, nodePtr);
	}
}

template <class T>
void LinkedList<T>::remove(T value)
{
	if (_head == NULL)
		return;
	else
	{
		Node* previous;
		Node* current = _head;

		while (current->_next != NULL && current->_value != value)
		{
			previous = current;
			current = current->_next;
		}

		if (current)
		{
			Node* temp = current;
			previous->_next = current->_next;
			delete temp;
		}
	}
}

template <class T>
void LinkedList<T>::display() const
{
	if (_head == NULL)
		return;
	else
	{
		cout << "\n\n";

		Node* nodePtr = _head;

		while (nodePtr != NULL)
		{
			if (nodePtr->_next != NULL)
			{
				cout << nodePtr->_value << ", ";

				nodePtr = nodePtr->_next;
			}
			else
			{
				cout << nodePtr->_value << "\n\n";

				nodePtr = nodePtr->_next;
			}
		}
	}
}

template <class T>
void LinkedList<T>::destroyList()
{
	if (_head == NULL)
		return;
	else
	{
		Node* nodePtr = _head;

		while (nodePtr != NULL)
		{
			Node* temp = nodePtr;
			nodePtr = nodePtr->_next;
			delete temp;
		}
	}
}