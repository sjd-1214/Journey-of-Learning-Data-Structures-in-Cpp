#include<iostream>
#include<string>
using namespace std;

class linearQueue {
private:
	int* que;
	int front;
	int rear;
	int capacity;
public:
	linearQueue(int size) :capacity(size) {
		front = rear = -1;
		que = new int[capacity];
	}

	~linearQueue() {
		delete[]que;
	}

	bool isEmpty() {
		if (front == -1  || rear == -1)
			return true;
		return false;
	}

	bool isFull() {
		if (rear == capacity - 1)
			return true;
		return false;
	}

	bool enQueue(int val) {
		
		if (isFull()) {
			cout << "The Queue is FULL can't add another element\n";
			return false;
		} 
		else if (isEmpty()) {
			front = rear = 0;
		} 
		else
			rear++;

		que[rear] = val;
		return true;
	}

	bool deQueue(int&num) {

		if (isEmpty()) {
			cout<<"The Queue is EMPTY can't add another element\n";
			return false;
		}

		if (rear == front) {
			rear = front = -1;
		}
		
		num = que[++front];
		return true;
	}

	void makeNull() {
		front = rear = -1;
		cout << "The Queue is NULLIFIED\n";
	}

	void display() {
		if (isEmpty()) {
			cout << "\nThe Queue is empty!\n";
			return;
		}

		cout << "\nQueue contents: [ ";
		for (int i = front; i <= rear; i++) {
			cout << que[i];
			if (i < rear) cout << " <- ";
		}
		cout << " ]\n";
	}
};



int main() {
	int size, choice, num;
	cout << "----------------------------\n";
	cout << " Welcome to the Queue System\n";
	cout << "----------------------------\n\n";

	cout << "Enter the size of the queue: ";
	cin >> size;

	linearQueue myQueue(size);

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
			cout << "Enter the number to enqueue: ";
			cin >> num;
			myQueue.enQueue(num);
			break;

		case 2:
			if (myQueue.deQueue(num)) {
				cout << "The dequeued number is: " << num << endl;
			}
			break;

		case 3:
			myQueue.display();
			break;

		case 4:
			myQueue.makeNull();
			break;

		case 5:
			cout << "Exiting the Queue System...\n";
			break;

		default:
			cout << "Invalid choice! Please try again.\n";
		}
	} while (choice != 5);
	return 0;
}