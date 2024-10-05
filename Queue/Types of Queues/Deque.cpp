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


int main() {
	int size, choice, value;

	cout << "-------------------------------\n";
	cout << " Welcome to the Deque Manager! \n";
	cout << "-------------------------------\n";
	cout << "Enter the size of the Deque: ";
	cin >> size;

	Deque dq(size);

	cout << "\nDeque initialized with size: " << size << "\n\n";

	do {
		cout << "======================================\n";
		cout << "            Deque Operations          \n";
		cout << "======================================\n";
		cout << "1. Insert at Front\n";
		cout << "2. Insert at Back\n";
		cout << "3. Remove from Front\n";
		cout << "4. Remove from Back\n";
		cout << "5. Display Deque\n";
		cout << "6. Exit\n";
		cout << "--------------------------------------\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "\nEnter the value to insert at Front: ";
			cin >> value;
			dq.insertFront(value);
			cout << "\n✔️ Successfully inserted " << value << " at the front!\n\n";
			break;

		case 2:
			cout << "\nEnter the value to insert at Back: ";
			cin >> value;
			dq.insertBack(value);
			cout << "\n✔️ Successfully inserted " << value << " at the back!\n\n";
			break;

		case 3:
			value = dq.removeFront();
			if (value != '\0')
				cout << "\n✔️ Successfully removed " << value << " from the front!\n\n";
			break;

		case 4:
			value = dq.removeBack();
			if (value != '\0')
				cout << "\n✔️ Successfully removed " << value << " from the back!\n\n";
			break;

		case 5:
			cout << "\nDisplaying current Deque elements:\n";
			dq.display();
			cout << endl;
			break;

		case 6:
			cout << "\nExiting the Deque Manager. Goodbye!\n";
			break;

		default:
			cout << "\n❌ Invalid choice! Please select a valid operation.\n";
			break;
		}

	} while (choice != 6);

	return 0;
}
