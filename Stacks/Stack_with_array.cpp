#include<iostream>
using namespace std;

class Stack {

	int* arr;
	int maxSize;
	int top;
public:
	Stack(int max) :maxSize(max), top(-1) {
		arr = new int[maxSize];
	}
	~Stack() {
		delete[] arr;
	}

	bool isFull() {
		return top == maxSize - 1;
	}

	bool isEmpty() {
		return top == -1;
	}

	bool push(int val) {
		if (isFull()) {
			cout << "The Stack is already full\n";
			return false;
		}

		top++;
		arr[top] = val;
		return true;
	}

	bool pop() {

		if (isEmpty()) {
			cout << "The Stack is Empty\n";
			return true;
		}

		top--;
		return true;

	}

	void display() {
		for (int i = top; i > -1; i--) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}


};

int main() {
	Stack s1(12);

	cout << "---- Stack Push Operations ----\n";
	for (int i = 1; i <= 12; i++) {
		if (s1.push(i)) {
			cout << "Pushed " << i << " onto the stack.\n";
		}
		else {
			cout << "Failed to push " << i << " as the stack is full.\n";
		}
	}

	cout << "\n---- Stack Display ----\n";
	s1.display();

	cout << "\n---- Stack Pop Operations ----\n";
	for (int i = 0; i < 5; i++) {
		if (s1.pop()) {
			cout << "Popped element from the stack.\n";
		}
	}

	cout << "\n---- Stack Display After Pop Operations ----\n";
	s1.display();

	cout << "\n---- Stack Empty Check ----\n";
	while (!s1.isEmpty()) {
		s1.pop();
		cout << "Popped element from the stack.\n";
	}

	cout << "Stack is now empty.\n";

	return 0;
}
