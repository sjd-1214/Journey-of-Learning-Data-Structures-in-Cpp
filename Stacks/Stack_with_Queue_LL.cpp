#include <iostream>

// Node class to represent each element in the linked list
class Node {
public:
    int data;
    Node* next;
    
    Node(int data) : data(data), next(nullptr) {}
};

// Queue ADT implemented using LinkedList
class QueueUsingLinkedList {
private:
    Node *front, *rear;

public:
    QueueUsingLinkedList() : front(nullptr), rear(nullptr) {}

    // Enqueue operation
    void enqueue(int x) {
        Node* temp = new Node(x);
        if (rear == nullptr) {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }

    // Dequeue operation
    void dequeue() {
        if (front == nullptr) {
            std::cout << "Queue is empty\n";
            return;
        }
        Node* temp = front;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
    }

    // Get the front element of the queue
    int getFront() {
        if (front == nullptr) {
            std::cout << "Queue is empty\n";
            return -1;
        }
        return front->data;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Display elements of the queue
    void display() {
        Node* temp = front;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

// Stack ADT implemented using Queue ADT
class StackUsingQueue {
private:
    QueueUsingLinkedList q1, q2;

public:
    void push(int x) {
        // Push element to q2
        q2.enqueue(x);

        // Move all elements from q1 to q2
        while (!q1.isEmpty()) {
            q2.enqueue(q1.getFront());
            q1.dequeue();
        }

        // Swap the names of q1 and q2
        std::swap(q1, q2);
    }

    void pop() {
        if (q1.isEmpty()) {
            std::cout << "Stack is empty\n";
            return;
        }

        // Remove the front element of q1
        q1.dequeue();
    }

    int top() {
        if (q1.isEmpty()) {
            std::cout << "Stack is empty\n";
            return -1;
        }

        // Return the front element of q1
        return q1.getFront();
    }

    bool isEmpty() {
        return q1.isEmpty();
    }

    void display() {
        if (q1.isEmpty()) {
            std::cout << "Stack is empty\n";
            return;
        }

        std::cout << "Stack elements: ";
        q1.display();
    }
};

int main() {
    StackUsingQueue stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Top element is: " << stack.top() << std::endl; // Output: 30

    stack.display(); // Output: Stack elements: 30 20 10

    stack.pop();
    std::cout << "Top element is: " << stack.top() << std::endl; // Output: 20

    stack.display(); // Output: Stack elements: 20 10

    stack.pop();
    std::cout << "Top element is: " << stack.top() << std::endl; // Output: 10

    stack.display(); // Output: Stack elements: 10

    stack.pop();
    std::cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << std::endl; // Output: Yes

    return 0;
}