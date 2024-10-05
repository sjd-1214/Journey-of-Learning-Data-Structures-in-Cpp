# Deque (Double-Ended Queue)

## Introduction

A **Deque (Double-Ended Queue)** is a data structure that allows insertion and removal of elements from both ends: the front and the back. It is a generalized version of both **stacks** and **queues**, offering more flexibility.

This `README` covers the types of queues, their functionality, differences between them, and real-world use cases to help intermediate programmers understand the various implementations and applications of queues.

## 1. Types of Queues

There are four primary types of queues:

1. **Simple Queue** (also known as Linear Queue)
2. **Circular Queue**
3. **Priority Queue**
4. **Deque (Double-Ended Queue)**

## 2. Functionality of Each Type

### 1. Simple Queue
- **FIFO** (First In, First Out): Elements are added at the rear (enqueue) and removed from the front (dequeue).
- Operations: `Enqueue`, `Dequeue`, `Front`, `Rear`, `IsEmpty`, `IsFull`

### 2. Circular Queue
- Similar to a Simple Queue but the rear wraps around to the front when the end of the queue is reached, forming a **circular structure**.
- Operations: `Enqueue`, `Dequeue`, `Front`, `Rear`, `IsEmpty`, `IsFull`

### 3. Priority Queue
- Elements are added based on their **priority**, not just their order of arrival. Higher priority elements are dequeued before lower priority ones.
- Operations: `Insert`, `Delete`, `Peek` (returns the highest priority element)

### 4. Deque (Double-Ended Queue)
- Allows insertion and deletion at **both ends** (front and rear).
- Two types of Deques:
  - **Input-Restricted Deque**: Insertion is restricted to one end, but deletion can be done from both ends.
  - **Output-Restricted Deque**: Deletion is restricted to one end, but insertion can be done from both ends.
- Operations: `InsertFront`, `InsertRear`, `DeleteFront`, `DeleteRear`, `GetFront`, `GetRear`, `IsEmpty`, `IsFull`

## 3. Differences Between Each Type

| Feature                    | Simple Queue                 | Circular Queue              | Priority Queue              | Deque                         |
|----------------------------|------------------------------|-----------------------------|-----------------------------|-------------------------------|
| **Insertion**               | Rear only                    | Rear only                   | Based on priority            | Both front and rear            |
| **Deletion**                | Front only                   | Front only                  | Based on priority            | Both front and rear            |
| **Order of Removal**        | FIFO                         | FIFO                        | By priority, not order       | FIFO or LIFO, depending on usage|
| **Wrapping**                | No                           | Yes                         | No                          | No                            |
| **Dynamic Size**            | Fixed                        | Fixed                       | Dynamic                      | Dynamic                        |
| **Use Case**                | Task management              | Memory-efficient queue       | Handling priority tasks       | Dual-ended operations           |

## 4. Real-World Example of Each Type of Queue

### 1. Simple Queue
- **Example**: A queue at a ticket counter. People arrive, and the first person to arrive is served first (FIFO).

### 2. Circular Queue
- **Example**: **Memory management** in computers where the circular buffer is used for efficiently utilizing memory. When the end is reached, it wraps around to use available space at the front.

### 3. Priority Queue
- **Example**: **Emergency rooms** in hospitals where patients are treated based on the severity of their condition (higher priority), not the order in which they arrived.

### 4. Deque (Double-Ended Queue)
- **Example**: **Undo/Redo operations** in text editors. Both ends are accessible: adding new operations or undoing the most recent one.

## 5. Why Use Deque?

Deques are extremely versatile and can act as both a **queue** and a **stack**. They provide more flexibility compared to simple or circular queues since you can insert and delete from both ends, making them ideal for a variety of use cases like **sliding window problems**, **palindrome checking**, and **double-ended task processing**.

## 6. Additional Concepts

### 1. **Queue Underflow and Overflow**
- **Underflow** occurs when attempting to dequeue from an empty queue.
- **Overflow** occurs when attempting to enqueue into a full queue (especially for fixed-size queues).

### 2. **Time Complexity**
- All basic operations (insertion, deletion, access) for most queue types take **O(1)** time, ensuring that queues are efficient for real-time applications.

### 3. **Queue Variants and Implementations**
- **Double-ended queues** are often implemented using **linked lists** or **dynamic arrays**.
- **Priority queues** can be implemented using **heaps** to ensure efficient priority management (O(log n) for insertions and deletions).

## 7. Conclusion

Queues are foundational data structures in computer science. Understanding the different types, their functionality, and real-world applications helps to choose the right queue for specific problems. Deques stand out for their flexibility and versatility, making them suitable for advanced data manipulation tasks.

## 8. Contact

Need assistance or further explanation about the implementation of Circular and Linear Queues? Feel free to reach out! I offer personal help with coding problems, and further detailed explanations, including code walkthroughs. Please note that assistance may be **paid**.

📧 Contact me at: **[sjdgithub1214@gmail.com](mailto:sjdgithub1214@gmail.com)**

---

Thank you for exploring Queues! 🚀 Happy Coding! 😊