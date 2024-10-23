#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = right = nullptr;
    }
};

class BST
{
private:
    Node *root;
    bool insertNode(Node *&rt, int val)
    {

        if (rt != nullptr)
        {

            if (val == rt->data)
            {
                cout << "Can't reinsert " << val << " - already exists in the tree\n";
            }

            if (val < rt->data)
            {
                insertNode(rt->left, val);
            }
            else if (val > rt->data)
            {
                insertNode(rt->right, val);
            }
        }
        else
        {
            Node *newNode = new Node(val);
            rt = newNode;
            return true;
        }
    }

    void inOrder(Node *rt)
    {
        if (rt != nullptr)
        {
            inOrder(rt->left);
            cout << rt->data << " ";
            inOrder(rt->right);
        }
    }

    int searchKey(Node *root, int data)
    {
    }

public:
    BST()
    {
        root = nullptr;
    }
    bool insert(int data)
    {
        return insertNode(root, data);
    }

    void taverse()
    {
        inOrder(root);
    }

    int search(int key)
    {
        int value = searchKey(root, key);
if (value != key || value == '\0') {
	cout << "The key --> "<<key<<" -is not found in the tree\n";
}
else {
	cout << "Key --> " << value << " -found\n";
	return value;
}
    }
};

int main() {
	BST t1;
	t1.insert(10);
	t1.insert(11);
	t1.insert(9);
	t1.insert(9);
	t1.taverse();
	return 0;
}
