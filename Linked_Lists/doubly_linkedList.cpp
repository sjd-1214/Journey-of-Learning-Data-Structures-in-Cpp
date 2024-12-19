#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node* prev;
	Node(int val) {
		data = val;
		next = NULL;
		prev = NULL;
	}
};

class linkedList {
	Node* head;
public:
	linkedList():head(NULL){}

	bool insertStart(int val) {
		Node* newNode = new Node(val);
		Node* current = head;

		if (head == NULL) {
			head = newNode;
			return true;
		}
		newNode->next = head;
		head = newNode;
		return true;
	}

	bool insertEnd(int val) {
		Node* newNode = new Node(val);

		if (head == NULL) {
			head = newNode;
			return true;
		}

		Node* current = head;

		while (current->next != NULL) {
			current = current->next;
		}

		newNode->prev = current;
		current->next = newNode;
		return true;
	}

	bool insertMiddle(int val) {
		Node* newNode = new Node(val);
		Node* current = head;

		int size = 0;

		while (current->next != NULL) {
			current = current->next;
			size++;
		}

		int index = size / 2;
		current = head;

		if (size % 2 == 0) {
			 // size is even for odd number of nodes bcoz index is starting from zero
			for (int count = 0; count < index-1; count++) {
				current = current->next;
			}
		}
		else {
			// size is odd for even number of nodes bcoz index is starting from zero
			for (int count = 0; count < index; count++) {
				current = current->next;
			}
		}

		newNode->next = current->next;
		current->next = newNode;
		newNode->prev = current;
		current->next->prev = newNode;
		return true;

	}

	bool deleteStart() {
		if (head == NULL) {
			cout << "The list is Empty" << endl;
			return false;
		}

		Node* current = head;
		head = current->next;
		current->next->prev = NULL;
		delete current;
		return true;
	}

	bool deleteEnd() {
		if (head == NULL) {
			cout << "The list is Empty" << endl;
			return false;
		}

		Node* current = head;
		while (current->next != NULL) {
			current = current->next;  // ->  = *.
		}

		current->prev->next = NULL;
		delete current;
		return true;
	}

	bool deleteMiddle() {
		if (head == NULL) {
			cout << "The list is Empty" << endl;
			return false;
		}

		if (head->next == NULL) {
			delete head;
			head = NULL;
			return true;
		}

		Node* current = head;
		int size = 0;
		while (current != NULL) {
			current = current->next;
			size++;
		}

		int index = size / 2;
		current = head;

		for (int count = 0; count < index - 1; count++) {
			current = current->next;
		}

		Node* nodeToDelete = current->next;
		current->next = nodeToDelete->next;

		nodeToDelete->next->prev = current;
		nodeToDelete->prev->next = nodeToDelete->next;

		delete nodeToDelete;
		return true;
	}


	void display() {
		Node* current = head;

		while (current != NULL) {
			cout << current->data << " ";
			current = current->next;
		}
	}
};


int main() {
	linkedList l1;
	l1.insertStart(10);
	l1.insertStart(20);
	l1.insertStart(30);
	l1.insertEnd(40);
	l1.insertMiddle(50);
	//l1.deleteStart();
	//l1.deleteEnd();
	l1.deleteMiddle();
	l1.display();
	return 0;
}