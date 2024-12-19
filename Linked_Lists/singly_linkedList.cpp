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

	bool insertSpecify(int index, int val)
	{
		
		if (index < 1)
		{
			cout << "INVALID INDEX\n";
			return false;
		}

		Node *newNode = new Node(val);

		// Handle insertion at the start
		if (index == 1)
		{
			insertStart(val);
			delete newNode;
			newNode = NULL;
			return true;
		}

		Node *current = head;
		int count = 0;
		index--;    // to insert at index starting from one
		// Traverse the list to find the insertion point
		while (current != NULL && count < index - 1)
		{
			count++;
			current = current->next;
		}

		// Handle insertion at the end or invalid index
		if (current == NULL)
		{
			if (count == index - 1)
			{
				return insertEnd(val); // Assuming insertEnd handles memory allocation
			}
			else
			{
				cout << "INDEX OUT OF BOUNDS\n";
				delete newNode;
				return false;
			}
		}

		// Insert the new node at the specified index
		newNode->next = current->next;
		current->next = newNode;
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
	lst1.insertSpecify(2, 50);
	lst1.deleteSpecify(5);
	lst1.display();
	lst1.insertSpecify(2, 60);
	lst1.display();
	lst1.insertSpecify(3, 70);
	lst1.display();
	return 0;
}