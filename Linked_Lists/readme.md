# Singly Linked List and Doubly Linked List

## Singly Linked List

A **Singly Linked List (SLL)** is a data structure that consists of nodes, where each node contains two parts:
1. **Data**: The value stored in the node.
2. **Pointer to the next node**: A reference to the next node in the list.

In a singly linked list:
- The list is traversed from the first node, called the **head**, to the last node, whose pointer to the next node is set to `NULL`, indicating the end of the list.
- Each node points only to the next node in the sequence, so the traversal can only occur in one direction (forward).
- **Insertion** and **deletion** operations can be performed at the beginning, middle, or end of the list.

### Key Operations

1. **Insert at the End**: Adds a new node at the end of the list by traversing through all nodes until the last node is found, then linking it to the new node.
   
2. **Insert at the Start**: A new node is added before the head, and the new node becomes the new head of the list.

3. **Insert at a Specific Position**: A new node can be inserted at a specific index by traversing to the desired position and adjusting the pointers accordingly.

4. **Delete from the End**: Removes the last node by traversing to the second last node and setting its next pointer to `NULL`.

5. **Delete from the Start**: Removes the head node and makes the next node the new head.

6. **Delete from a Specific Position**: Removes a node at a specific position by traversing to the node before it and adjusting pointers to bypass the node to be deleted.

### Advantages
- Efficient memory usage since each node only stores a single pointer.
- Easy to insert or delete elements at the beginning or end without needing to shift elements (as in arrays).

### Disadvantages
- Lack of backward traversal. Once you move forward, there’s no way to go back to the previous node.
- Searching for an element requires traversing the entire list, as there’s no random access like in arrays.


## Doubly Linked List

A **Doubly Linked List (DLL)** is a more advanced version of the singly linked list where each node contains three parts:
1. **Data**: The value stored in the node.
2. **Pointer to the next node**: A reference to the next node in the list.
3. **Pointer to the previous node**: A reference to the previous node, allowing bidirectional traversal.

In a doubly linked list:
- You can traverse the list in both forward and backward directions.
- Every node points to both the next and the previous node, making it possible to easily move back and forth between nodes.

### Key Operations

1. **Insert at the Start**: Similar to SLL, but the new node’s previous pointer is set to `NULL` and the next pointer of the new node is set to the old head. The old head's previous pointer is updated to the new node.
   
2. **Insert at the End**: The new node is linked to the last node, and its next pointer is set to `NULL`. The last node’s next pointer is updated to point to the new node, while the new node’s previous pointer points to the last node.

3. **Insert in the Middle**: A new node can be inserted at a specific position, and both the next and previous pointers of adjacent nodes are updated accordingly.

4. **Delete from the Start**: The head node is removed, the next node becomes the new head, and its previous pointer is set to `NULL`.

5. **Delete from the End**: The last node is removed, and the second-to-last node becomes the new end, with its next pointer set to `NULL`.

6. **Delete from the Middle**: A node in the middle of the list is removed by adjusting both the next pointer of the previous node and the previous pointer of the next node to bypass the node being deleted.

### Advantages
- Allows **bidirectional traversal**, which makes certain algorithms and operations (like finding the previous element) easier and more efficient.
- Insertion and deletion of nodes in the middle of the list are more straightforward since we have access to both the previous and next nodes.

### Disadvantages
- Requires more memory due to the extra pointer (to the previous node) in each node.
- More complex implementation due to the need to maintain two pointers for each node.

### Use Cases of SLL vs. DLL
- **Singly Linked List** is preferred when memory is limited, and backward traversal is not required.
- **Doubly Linked List** is preferred when frequent traversal in both directions is necessary, such as in applications like undo functionality in software, browser history, or implementing deque (double-ended queue).

---

If you need further explanation or personalized assistance, feel free to contact me at **sjdgithub1214@gmail.com**. Please note that detailed assistance may be **paid**.
