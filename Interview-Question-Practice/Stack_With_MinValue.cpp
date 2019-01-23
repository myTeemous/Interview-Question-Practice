#include <iostream>
using namespace std;

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
	Stack() { _top = NULL; }
	~Stack() { destroyStack(); }
	bool isEmpty() const;
	void push(int value);
	int pop(int &num);
	int getMin(int &num) const;
	void destroyStack();
};

int main() {

	cout << "\n\n";
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
	else if (value < _top->_minValue)
		_top = new Node(value, value, _top);
	else
		_top = new Node(value, _top->_minValue, _top);
}

int Stack::pop(int &num) {

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

int Stack::getMin(int &num) const {

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