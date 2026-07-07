#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class List
{
public:

    Node* head;
    Node* tail;

    List()
    {
        head = tail = NULL;
    }

    void push_back(int val)
    {
        Node* newNode = new Node(val);

        if(head == NULL)
        {
            head = tail = newNode;
            return;
        }

        tail->next = newNode;
        tail = newNode;
    }

    void reverse()
    {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        tail = head;

        while(curr != NULL)
        {
            next = curr->next;

            curr->next = prev;

            prev = curr;

            curr = next;
        }

        head = prev;
    }

    void print()
    {
        Node* temp = head;

        while(temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }
};

int main()
{
    List ll;

    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);

    cout << "Original List:" << endl;
    ll.print();

    ll.reverse();

    cout << "Reversed List:" << endl;
    ll.print();

    return 0;
}