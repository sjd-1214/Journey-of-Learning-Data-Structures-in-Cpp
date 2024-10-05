#include<iostream>
using namespace std;

class Deque {
	int* arr;
	int maxSize, rear, front;
public:
	Deque(int size) :maxSize(size), rear(-1), front(-1) {
		arr = new int[maxSize];
	}
	~Deque() {
		delete[]arr;
	}

	bool isEmpty() {
		if (rear == -1 && front == -1)
			return true;
		return false;
	}

	bool isFull() {
		if ((front == 0 && rear == maxSize - 1) || (front == (rear + 1) % maxSize))
			return true;
		return false;

	}

	void insertFront(int val) {
		if (isFull()) {
			cout << "Overflow-The deque is FULL\n";
			return;
		}

		if (isEmpty()) {
			rear = front = 0;
		}
		else if (front == 0) {
			front = maxSize - 1;
		}
		else {
			front--;
		}

		arr[front] = val;
	}

	void insertBack(int val) {
		if (isFull()) {
			cout << "Overflow-The deque is FULL\n";
			return;
		}

		if (isEmpty()) {
			front = rear = 0;
		}
		else if (rear == maxSize - 1) {
			rear = 0;
		}
		else {
			rear++;
		}

		arr[rear] = val;
	}

	int removeFront() {
		int data = 0;
		if (isEmpty()) {
			cout << "Underflow-The deque is EMPTY\n";
			return '\0';
		}

		data = arr[front];

		if (front == maxSize - 1) {
			front = 0;
		}
		else if (front == rear) {
			front = rear = -1;
		}
		else {
			front++;
		}

		return data;
	}

	int removeBack() {
		int data = 0;
		if (isEmpty()) {
			cout << "Underflow-The deque is EMPTY\n";
			return '\0';
		}

		data = arr[rear];

		if (rear == front) {
			front = rear = -1;
		}
		else if (rear == 0) {
			rear = maxSize - 1;
		}
		else {
			rear--;
		}

		return data;
	}

	void display() {
		if (isEmpty()) {
			cout << "Deque is empty!" << endl;
			return;
		}
		cout << "Deque elements: ";
		if (rear >= front) {
			for (int i = front; i <= rear; i++) {
				cout << arr[i] << " ";
			}
		}
		else {
			for (int i = front; i < maxSize; i++) {
				cout << arr[i] << " ";
			}
			for (int i = 0; i <= rear; i++) {
				cout << arr[i] << " ";
			}
		}
		cout << endl;
	}
};


