#include <iostream>
#include <queue>

class StackUsingQueues {
private:
    std::queue<int> q1, q2;

public:
    void push(int x) {
        // Push element to q2
        q2.push(x);

        // Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Swap the names of q1 and q2
        std::swap(q1, q2);
    }

    void pop() {
        if (q1.empty()) {
            std::cout << "Stack is empty\n";
            return;
        }

        // Remove the front element of q1
        q1.pop();
    }

    int top() {
        if (q1.empty()) {
            std::cout << "Stack is empty\n";
            return -1;
        }

        // Return the front element of q1
        return q1.front();
    }

    bool isEmpty() {
        return q1.empty();
    }

    void display() {
        if (q1.empty()) {
            std::cout << "Stack is empty\n";
            return;
        }

        std::queue<int> temp = q1;
        std::cout << "Stack elements: ";
        while (!temp.empty()) {
            std::cout << temp.front() << " ";
            temp.pop();
        }
        std::cout << std::endl;
    }
};

int main() {
    StackUsingQueues stack;

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