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
        return searchKey(root, key);
    }
};

int main()
{

    return 0;
}
