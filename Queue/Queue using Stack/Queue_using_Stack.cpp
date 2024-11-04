#include<iostream>
#include<string>
using namespace std;
void displayMenu();
class Node {
public:
	int data;
	Node* next;
	Node(int val):data(val),next(nullptr){}
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr){}

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        Node* current = top;
        top = current->next;
        delete current;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    int Top() {
        return top->data;
    }

    void display() {
        Node* current = top;
        while (current != nullptr) {
            cout << " " << current->data;
            current = current->next;
        }
    }

    void reverse() {
        Node* prev = nullptr;
        Node* current = top;
        Node* Next = current; 

        while (current != nullptr) {
            Next = Next->next;   
            current->next = prev;
            prev = current;
            current = Next; 
        }

        top = prev; 
    }
};

class Queue {
    Stack stk;
public:
    bool isEmpty() {
        if (stk.isEmpty()) {
            return true;
        }
        return false;
    }

    bool enqueue(int val) {
        stk.push(val);
        return true;
    }

    bool dequeue() {
        if (stk.isEmpty()) {
            cout << "The Queue is EMPTY\n";
            return false;
        }
        stk.reverse();
        stk.pop();
        stk.reverse();
        return true;
    }

    int peek() {
        stk.reverse();
        int peekValue = stk.Top();
        stk.reverse();
        return peekValue;
    }

    void display() {
        if (stk.isEmpty()) {
            cout << "Queue is EMPTY" << endl;
            return;
        }
        cout << "Queue contents (front to rear): ";
        Stack tempStack = stk;
        tempStack.reverse();
        tempStack.display();
        cout << endl;
    }
};

void displayMenu() {
    cout << "\n*************************************************\n";
    cout << "*            Queue Management System            *\n";
    cout << "*************************************************\n";
    cout << "1. Enqueue\n";
    cout << "2. Dequeue\n";
    cout << "3. Peek\n";
    cout << "4. Display Queue\n";
    cout << "5. Exit\n";
    cout << "*************************************************\n";
    cout << "Enter your choice: ";
}

int main() {
    Queue q;
    int choice, value;

    while (true) {
        displayMenu();
        cin >> choice;

        if (choice == 1) {

            cout << "\nEnter a value to enqueue: ";
            cin >> value;
            q.enqueue(value);
            cout << "\nSuccessfully enqueued " << value << " to the queue.\n";
        }
        else if (choice == 2) {
            if (q.dequeue()) {
                cout << "\nSuccessfully dequeued the front element.\n";
            }
        }
        else if (choice == 3) {
            value = q.peek();
            if (value != -1) {
                cout << "\nThe front element is: " << value << endl;
            }
        }
        else if (choice == 4) {
            cout << "\nDisplaying the current state of the queue:\n";
            q.display();
        }
        else if (choice == 5) {
            cout << "\nExiting the program. Thank you!\n";
            return 0;
        } 
        else {

            cout << "\nInvalid choice. Please try again.\n";
        }

        cout << "\n--------------------------------------------\n";
    }

    return 0;
}
