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

public:
BST() {
	root = nullptr;
}

};

int main()
{

    return 0;
}
