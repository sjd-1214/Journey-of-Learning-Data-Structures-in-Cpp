#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
	Node(int val)
	{
		data = val;
		next = NULL;
	}
};

class linkedList
{
private:
	Node *head;

public:
	linkedList()
	{
		head = NULL;
	}

	~linkedList()
	{
		delete head;
		head = NULL;
	}

	bool insertEnd(int val)
	{
		Node *newNode = new Node(val);
		Node *current = head;
		if (head == NULL)
		{
			head = newNode;
			return true;
		}
		else
		{
			while (current->next != NULL)
			{
				current = current->next;
			}
			current->next = newNode;
			return true;
		}
	}

	bool insertStart(int val)
	{
		Node *newNode = new Node(val);
		if (head == NULL)
		{
			head = newNode;
			return true;
		}
		else
		{
			newNode->next = head;
			head = newNode;
			return true;
		}
	}

	Node* findMiddle(){
	    Node *slow = head;
	    Node *fast = head;
	    Node *prev = NULL; // To keep track of the node before the middle node

	    while(fast != NULL && fast->next != NULL){
	        prev = slow;
	        slow = slow->next;
	        fast = fast->next->next;
	    }

	    // If the list has an even number of nodes, return the node before the middle
	    if (fast == NULL) {
	        return prev;
	    }

	    return slow;
	}

	bool insertMiddle(int val)
	{
	    if (head == NULL)
	    {
	        head = new Node(val);
	        return true;
	    }

	    Node *middle = findMiddle();
	    Node *newNode = new Node(val);

	    if (middle == head && head->next == NULL) {
	        // If there's only one element, insert after it
	        newNode->next = head->next;
	        head->next = newNode;
	    } else {
	        newNode->next = middle->next;
	        middle->next = newNode;
	    }

	    return true;
	}

	bool deleteEnd()
	{
		if (head == NULL)
		{
			cout << "The list is EMPTY\n";
		}

		if (head->next == NULL)
		{
			delete head;
			head = NULL;
			return true;
		}

		Node *current = head;
		while (current->next->next != NULL)
		{
			current = current->next;
		}

		delete current->next;
		current->next = NULL;

		return true;
	}

	bool deleteStart()
	{
		if (head == NULL)
		{
			cout << "The list is EMPTY\n";
		}

		if (head->next == NULL)
		{
			delete head;
			head = NULL;
			return true;
		}

		Node *current = head;
		head = current->next;
		delete current;
		return true;
	}

	bool deleteSpecify(int index)
	{
		if (index <= 0)
		{
			cout << "INVALID INDEX - Index starts from 1\n";
			return false;
		}

		if (index == 1)
		{
			Node *temp = head;
			head = head->next;
			delete temp;
			return true;
		}

		Node *current = head;
		int count = 1;

		while (current != NULL && count < index - 1)
		{
			current = current->next;
			count++;
		}

		if (current->next == NULL && count != (index - 1) - 1)
		{
			cout << "INDEX OUT OF BOUNDS\n";
			return false;
		}

		Node *temp = current->next;
		current->next = temp->next;
		delete temp;
		return true;
	}

	void display()
	{
		if (head == NULL)
		{
			cout << "The list is Empty\n";
		}
		else
		{
			Node *current = head;
			while (current != NULL)
			{
				cout << current->data << " ";
				current = current->next;
			}
		}
		cout << endl;
	}
};

int main()
{
	linkedList lst1;
	lst1.display();
	lst1.insertEnd(10);
	lst1.insertEnd(20);
	lst1.insertEnd(30);
	lst1.insertStart(40);
	lst1.display();
	lst1.deleteSpecify(4);
	lst1.display();
	lst1.insertMiddle(50);
	lst1.display();
	lst1.insertMiddle(60);
	lst1.display();
	return 0;
}