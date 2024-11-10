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
        if (arr.size() == 0)
            return NULL;
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
    static Node *insertHead(Node *head, int val)
    {
        Node *temp = new Node(val, head);
        head = temp;
        return head;
    }
    static Node *insertTail(Node *head, int val)
    {
        if (head == NULL)
            return new Node(val);
        Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new Node(val);
        return head;
    }
    static Node *insertPosition(Node *head, int val, int k)
    {
        if (head == NULL)
        {
            if (k == 1)
            {
                return new Node(val);
            }
            else
            {
                return head;
            }
        }

        if (k == 1)
        {
            return new Node(val, head);
        }

        Node *temp = head;
        int cnt = 1;
        while (temp != NULL)
        {
            if (cnt == k - 1)
            {
                Node *x = new Node(val, temp->next);
                temp->next = x;
                break;
            }
            temp = temp->next;
            cnt++;
        }
        return head;
    }

    static Node *insertbeforeValue(Node *head, int val, int el)
    {
        if (head == NULL)
        {
            return head;
        }

        if (head->data == el)
        {
            return new Node(val, head);
        }

        Node *temp = head;
        while (temp->next != NULL)
        {
            if (temp->next->data == el)
            {
                Node *x = new Node(val, temp->next);
                temp->next = x;
                break;
            }
            temp = temp->next;
        }
        return head;
    }
};

#ifdef NO_COMMIT
// This code won't be compiled or committed
int main()
{
    vector<int> arr = {2, 4, 6, 8};
    Node *head = Node::convertArr2LL(arr);
    head = Node::deleteEl(head, 5);
    // head = Node::insertHead(head, 100);
    // head = Node::insertHead(head, 200);
    // head = Node::insertHead(head, 300);
    // head = Node::insertTail(head, 600);
    // head = Node::insertPosition(head, 600, 6);
    head = Node::insertbeforeValue(head, 600, 6);
    Node::print(head);
}
#endif