#include <vector>
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

public:
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
    Node(int data, Node *next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
};

// Utilities Functions
Node *convertArr2DLL(vector<int> &arr)
{
    if (arr.size() == 0)
    {
        return NULL;
    }
    Node *head = new Node(arr[0]);
    Node *pre = head;
    for (int i = 0; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i], nullptr, pre);
        pre->next = temp;
    }

    return head;
}

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

Node *deleteHead(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    Node *pre = head;
    head = head->next;
    head->prev = nullptr;
    pre->next = nullptr;

    delete pre;
    return head;
}

Node *deleteTail(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    Node *newTail = tail->prev;
    tail->prev = nullptr;
    newTail->next = nullptr;
    delete tail;
    return head;
}