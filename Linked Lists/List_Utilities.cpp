#include <vector>
#include <iostream>
using namespace std;
class Node
{
private:
    int data;
    Node *next;

public:
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }

    // Utilities Functions

    // Convert Array to Linked List
    static Node *convertArr2LL(vector<int> &arr)
    {
        Node *head = new Node(arr[0]);
        Node *curr = head;
        for (int i = 1; i < arr.size(); i++)
        {
            Node *temp = new Node(arr[i]);
            curr->next = temp;
            curr = curr->next;
        }
        return head;
    }

    // Traverse the Linked List
    static void print(Node *head)
    {
        Node *curr = head;
        while (curr != nullptr)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
    }

    // Length of Linked List
    int lengthOfLL(Node *head)
    {
        int cnt = 0;
        Node *curr = head;
        while (curr != NULL)
        {
            cnt++;
            curr = curr->next;
        }

        return cnt;
    }

    // Linear Search in Linked List
    bool searchLL(Node *head, int key)
    {
        Node *curr = head;
        while (curr)
        {
            if (curr->data == key)
            {
                return true;
            }
            curr = curr->next;
        }
        return false;
    }

    // Delete at Begin / head
    // TC O(1)
    // SC O(1)
    Node *deleteAtBegin(Node *head)
    {
        if (head == NULL)
            return head;
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    // Delete at End / tail
    // TC O(n)
    // SC O(1)
    Node *deleteAtEnd(Node *head)
    {
        if (head == NULL || head->next == NULL)
            return NULL;
        // atleast 2 Nodes
        Node *curr = head;

        while (curr->next->next != NULL)
        {
            curr = curr->next;
        }

        Node *temp = curr->next;
        delete temp;

        curr->next = NULL;

        return head;
    }

    // Delete at Kth position
    // TC O(n)
    // SC O(1)
    Node *deleteK(Node *head, int k)
    {
        if (head == NULL)
            return NULL;

        if (k == 1)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        int cnt = 1;
        Node *temp = head;
        while (temp != NULL)
        {
            if (cnt == k - 1)
            {
                Node *temp2 = temp->next;
                temp->next = temp->next->next;
                delete temp2;
                return head;
            }
            temp = temp->next;
            cnt++;
        }
        return head;
    }

    static Node *deleteEl(Node *head, int val)
    {
        if (head == NULL)
            return NULL;

        if (head->data == val)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        Node *temp = head;
        while (temp->next != NULL)
        {
            if (temp->next->data == val)
            {
                Node *temp2 = temp->next;
                temp->next = temp->next->next;
                delete temp2;
                return head;
            }
            temp = temp->next;
        }
        return head;
    }
};
