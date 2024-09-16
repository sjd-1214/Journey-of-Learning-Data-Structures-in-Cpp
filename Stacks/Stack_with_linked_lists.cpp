#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

class Stack {
private:
    Node* top;
    int maxSize;
    int currentSize;

public:
    Stack(int max) : top(NULL), maxSize(max), currentSize(0) {}

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    bool push(int val) {
        if (isFull()) {
            cout << "The stack is already full\n";
            return false;
        }

        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
        currentSize++;
        return true;
    }

    bool pop() {
        if (isEmpty()) {
            cout << "The Stack is Empty - Nothing to pop\n";
            return false;
        }

        Node* current = top;
        top = current->next;
        currentSize--;
        delete current;
        return true;
    }

    bool isFull() {
        return currentSize == maxSize;
    }

    bool isEmpty() {
        return top == NULL;
    }

    void display() {
        Node* current = top;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Stack stack(10);

    cout << "========== Stack Operations ==========\n";

    cout << "\nPushing elements onto the stack:\n";
    for (int i = 10; i <= 100; i += 10) {
        if (stack.push(i)) {
            cout << "Pushed " << i << " into the stack.\n";
        }
        else {
            break;
        }
    }

    cout << "\nCurrent Stack: ";
    stack.display();

    cout << "\n\nPopping 5 elements from the stack:\n";
    for (int i = 0; i < 5; i++) {
        if (stack.pop()) {
            cout << "Popped an element from the stack.\n";
        }
    }

    cout << "\nCurrent Stack after popping: ";
    stack.display();

    cout << "\n========== End of Stack Operations ==========\n";

    return 0;
}

