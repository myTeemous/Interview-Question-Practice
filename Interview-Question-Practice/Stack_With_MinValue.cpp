#include <iostream>
using namespace std;

/*
Implementation of a typical stack that also keeps track of the minimum value in the stack.
Each node has a minValue. The values of the subsequent nodes pushed onto the stack are 
compared to the minValue of the previous node. If value <= minValue then value will be
stored as the minValue of the node being pushed onto the stack. This ensures that you don't
have to search for the minValue everytime you pop from the stack.
--------------------------------------------------------------------------------------------
The operations of the stack, push, pop, isEmpty, and getMin are all O(1) time.
*/

class Stack {

	struct Node {

		int _value;
		int _minValue;
		Node* _next;
		Node(int value, int minValue, Node* next = NULL):
			_value(value), _minValue(minValue), _next(next)
		{}
	};

	Node* _top;

public:
	Stack(): _top(NULL) {}
	~Stack() { destroyStack(); }
	bool isEmpty() const;
	void push(int value);
	int pop();
	int getMin() const;
	void destroyStack();
};

int main() {

	Stack myStack;

	myStack.push(3);
	myStack.push(8);
	myStack.push(2);
	myStack.push(7);
	myStack.push(11);
	myStack.push(1);
	myStack.push(2);
	myStack.push(5);
	myStack.push(10);
	myStack.push(9);

	int num = 0;

	while (!myStack.isEmpty()) {

		cout << "min:"<< myStack.getMin() << "  ";
		cout << myStack.pop() << endl;
	}

	cout << "\n";
	cin.get();

	return 0;
}

bool Stack::isEmpty() const {

	if (_top == NULL)
		return true;
	else
		return false;
}

void Stack::push(int value) {

	if (isEmpty())
		_top = new Node(value, value, _top);
	else if (value <= _top->_minValue)
		_top = new Node(value, value, _top);
	else
		_top = new Node(value, _top->_minValue, _top);
}

int Stack::pop() {

	int num;

	if (isEmpty())
		cout << "\n\nstack is empty\n\n";
	else {

		num = _top->_value;
		Node* temp = _top;
		_top = _top->_next;
		delete temp;
	}

	return num;
}

int Stack::getMin() const {

	if (isEmpty())
		cout << "\n\nstack is empty\n\n";
	else
		return _top->_minValue;
}

void Stack::destroyStack() {

	while (_top != NULL) {

		Node* temp = _top;
		_top = _top->_next;
		delete temp;
	}
}