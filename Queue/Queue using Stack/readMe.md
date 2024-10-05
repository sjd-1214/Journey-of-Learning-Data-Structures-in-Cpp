# Queue Using Stack

## 1. Functionality

A **Queue** is a linear data structure that follows the **First In, First Out (FIFO)** principle, meaning the first element added to the queue will be the first one to be removed.

In this implementation, we are using **two stacks** to simulate the behavior of a queue. The stacks are Last In, First Out (LIFO) structures, but by using two stacks, we can reverse the order of elements twice, thus achieving the FIFO behavior of a queue.

### Basic Operations:

- **Enqueue(x)**: Adds an element `x` to the back of the queue.
- **Dequeue()**: Removes and returns the element at the front of the queue.
- **Peek()**: Returns the front element without removing it.
- **IsEmpty()**: Checks whether the queue is empty or not.

## 2. Why Queues?

Queues are essential for managing data in situations where **order** matters. The FIFO nature of queues ensures that the **first task** or element added is the **first to be processed**, making them useful in many real-world scenarios.

### Common Use Cases:
- **Task Scheduling**: Handling tasks in the order they arrive, like in CPU task scheduling.
- **Breadth-First Search (BFS)**: Ensuring that nodes are processed level by level in graph traversal.
- **Data Streaming**: Processing data in the order it's received, such as logs or requests.

## 3. Comparison: Queue vs. Stack, Linked List, and Array

| Feature               | Queue                       | Stack                       | Linked List                | Array                       |
|-----------------------|-----------------------------|-----------------------------|----------------------------|-----------------------------|
| **Order**             | FIFO (First In, First Out)   | LIFO (Last In, First Out)    | Can be sequential or random | Can be accessed sequentially or randomly |
| **Access**            | Only front and back elements| Only top element             | Can access any node         | Can access any index directly |
| **Insertion/Deletion**| O(1) from front/back         | O(1) from top                | O(1) at front or back       | O(n) for insertion/deletion in the middle |
| **Memory Efficiency** | Dynamic memory allocation    | Dynamic memory allocation    | Dynamic memory allocation   | Fixed size or dynamically resized         |
| **Use Cases**         | Task scheduling, BFS         | Undo/Redo, DFS               | Dynamic data storage        | Static data storage, indexing             |
| **Implementation**    | Can be implemented using stacks| Built-in stack operations   | Pointers and references     | Index-based access and storage            |

## 4. Real-World Example of Queue

A common real-world example of a queue is a **line at a ticket counter**. The first person to arrive in line will be the first one to be served, and new people join the end of the line.

### Other examples:
- Customer service systems (handling customer requests in the order they come in)
- Printers (handling print jobs in the order they are submitted)
- Network packets (handling data packets as they arrive for processing)

## 5. Why We Use Queues Instead of Linked Lists?

Although linked lists allow efficient insertions and deletions, queues offer a more **natural structure** for handling tasks where order matters. The FIFO nature of queues provides predictable, orderly data management, which is more intuitive for problems where processing must follow the order of arrival.

Queues are also simpler to use for specific operations like **task scheduling**, as they inherently manage the order, whereas linked lists would require more manual management for FIFO behavior.

## 6. Contact

Need assistance or further explanation about the implementation of Circular and Linear Queues? Feel free to reach out! I offer personal help with coding problems, and further detailed explanations, including code walkthroughs. Please note that assistance may be **paid**.

📧 Contact me at: **[sjdgithub1214@gmail.com](mailto:sjdgithub1214@gmail.com)**

---

Thank you for exploring Queues! 🚀 Happy Coding! 😊