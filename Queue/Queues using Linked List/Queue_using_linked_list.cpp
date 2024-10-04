#include<iostream>
#include<iomanip>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node(int val) :data(val), next(nullptr) {}\
};

class Queue {
private:
	Node* front;
	Node* rear;
public:

	Queue() :front(nullptr), rear(nullptr) {}
	~Queue(){
		clear();
	}

	bool isEmpty() {
		if (front == nullptr)
			return true;
		return false;
	}

	bool enqueue(int val) {
		Node* newNode = new Node(val);
		if (isEmpty()) {
			front = rear = newNode;
			return true;
		}

		rear->next = newNode;
		rear = newNode;
		return true;
	}

	bool dequeue(int& num) {
		if (isEmpty()) {
			cout << "The Queue is EMPTY\n";
			return false;
		}

		num = front->data;
		Node* current = front;
		front = front->next;
		if (front == nullptr) {
			rear = nullptr;
		}
		delete current;
		return true;
	}

	int peek() {
		if (isEmpty()) {
			cout << "The Queue is EMPTY\n";
			return '\0';
		}
		return front->data;
	}

	void clear() {
		while (!isEmpty()) {
			int temp;
			dequeue(temp);
		}
	}

	void display() {
		cout << "\n-----------------------------\n";
		cout << "          Queue Contents     \n";
		cout << "-----------------------------\n";
		if (isEmpty()) {
			cout << "The Queue is currently EMPTY.\n";
			cout << "-----------------------------\n";
			return;
		}

		cout << "| ";
		Node* current = front;
		while (current != nullptr) {
			cout << setw(2) << current->data << " | ";
			current = current->next;
		}
		cout << "\n-----------------------------\n";
	}
};


int main() {
	int choice, num, size;

	cout << "----------------------------------\n";
	cout << "    Welcome to the Linked Queue   \n";
	cout << "----------------------------------\n\n";
	Queue q1;

	do {
		cout << "\n===============================\n";
		cout << "       Menu Options            \n";
		cout << "===============================\n";
		cout << " 1. Enqueue\n";
		cout << " 2. Dequeue\n";
		cout << " 3. Display Queue\n";
		cout << " 4. Exit\n";
		cout << "===============================\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Enter the number to enqueue: ";
			cin >> num;
			if (q1.enqueue(num)) {
				cout << num << " has been added to the queue.\n";
			}
			break;

		case 2:
			if (q1.dequeue(num)) {
				cout << num << " has been removed from the queue.\n";
			}
			break;

		case 3:
			q1.display();
			break;

		case 4:
			cout << "\nExiting the Queue System...\n";
			break;

		default:
			cout << "Invalid choice! Please try again.\n";
		}
	} while (choice != 4);

	cout << "\nThank you for using the Linked Queue System. Have a great day!\n";
	return 0;
}