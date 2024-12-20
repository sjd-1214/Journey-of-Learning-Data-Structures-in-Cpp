#include <iostream>
#include <string>
using namespace std;
class node
{
public:
    int data;
    int Priority;
    node *next;
    node()
    {
        data = Priority = NULL;
        next = NULL;
    }
};
class Priority_Queue
{
private:
    node *front, *rear;

public:
    Priority_Queue()
    {
        front = rear = NULL;
    }
    bool isEmpty()
    {
        if (front == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool EnQueue(int Val, int Priority)
    {
        node *newNode = new node;
        newNode->data = Val;
        newNode->Priority = Priority;
        if (isEmpty())
        {
            front = newNode;
            // newNode->next = NULL;
            return true;
        }
        if (Priority < front->Priority)
        {
            newNode->next = front;
            front = newNode;
            return true;
        }
        else
        {
            node *curr = front;
            while (curr && curr->next->Priority < Priority)
            {
                curr = curr->next;
            }
            newNode->next = curr->next;
            curr->next = newNode;
            newNode = curr;
            return true;
        }
    }
    bool DeQueue()
    {
        if (isEmpty())
        {
            cout << " Priority Queue is Empty" << endl;
            return false;
        }
        node *Temp = front;
        front = front->next;
        delete Temp;
    }
    void Display()
    {
        node *Temp = front;
        cout << " Priority_Queue = ";
        while (Temp != NULL)
        {
            cout << " " << Temp->data << " ";
            Temp = Temp->next;
        }
        cout << endl;
    }
};
int main()
{
    Priority_Queue pq;
    pq.EnQueue(1, 50);
    pq.EnQueue(2, 40);
    pq.EnQueue(3, 30);
    pq.EnQueue(4, 20);
    pq.EnQueue(5, 10);
    pq.EnQueue(99, 25);
    pq.Display();
    system("pause");
    return 0;
}