#include<iostream>
using namespace std;

class Queue {
private:
	int* que;
	int capacity;
	int front;
	int rear;
public:
	Queue(int size) {
		front = rear = -1;
		capacity = size;
		que = new int[capacity];
	}

	~Queue() { delete[]que; }

	bool isFull() {
		return ((rear + 1) % capacity == front);
	}

	bool isEmpty() {
		return (rear == -1 && front == -1);
	}

	void makeNull() {
		rear = front = -1;
		cout << "The Queue is NULLIFIED\n";
	}

	bool enQueue(int val) {
		if (isFull()) {
			cout << "The Queue is FULL\n";
			return false;
		}
		if (isEmpty())
			rear = front = 0;
		else
			rear = (rear + 1) % capacity;
		que[rear] = val;
		return true;
	}

	bool deQueue(int& num) {
		if (isEmpty()) {
			cout << "The Queue is EMPTY\n";
			return false;
		}
		num = que[front];
		if (front == rear)
			front = rear = -1;
		else
			front = (front + 1) % capacity;
		return true;
	}

	void display() {
		cout << endl;
		if (isEmpty()) {
			cout << "The Queue is Empty\n";
			return;
		}

		cout << "Queue contents: [ ";
		for (int i = front; i != rear; i = (i + 1) % capacity) {
			cout << que[i] << " ";
		}
		cout << que[rear] << " ]\n";
	}
};

int main() {
	int choice, num, size;

	cout << "----------------------------------\n";
	cout << "    Welcome to the Circular Queue\n";
	cout << "----------------------------------\n\n";

	cout << "Enter the size of the queue: ";
	cin >> size;

	Queue q1(size);

	do {
		cout << "\n======================================\n";
		cout << " 1. Enqueue\n";
		cout << " 2. Dequeue\n";
		cout << " 3. Display Queue\n";
		cout << " 4. Make Queue Null (Empty)\n";
		cout << " 5. Exit\n";
		cout << "======================================\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "\nEnter the number to enqueue: ";
			cin >> num;
			if (q1.enQueue(num)) {
				cout << num << " is successfully added to the queue!\n";
			}
			break;

		case 2:
			if (q1.deQueue(num)) {
				cout << "\n" << num << " is removed from the queue!\n";
			}
			break;

		case 3:
			cout << "\nCurrent Queue contents: ";
			q1.display();
			break;

		case 4:
			q1.makeNull();
			break;

		case 5:
			cout << "\nExiting the Queue System...\n";
			break;

		default:
			cout << "Invalid choice! Please try again.\n";
		}

	} while (choice != 5);

	cout << "\nThank you for using the Circular Queue System. Have a great day!\n";
	return 0;
}
