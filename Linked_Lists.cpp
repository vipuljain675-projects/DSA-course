#include <iostream>
using namespace std;

// =======================
// Node Class
// =======================

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

// =======================
// Linked List Class
// =======================

class List
{
    Node* head;
    Node* tail;

public:

    List()
    {
        head = tail = NULL;
    }

    // Push Front
    void push_front(int val)
    {
        Node* newNode = new Node(val);

        if(head == NULL)
        {
            head = tail = newNode;
            return;
        }

        newNode->next = head;
        head = newNode;
    }

    // Push Back
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

    // Insert at Position (0-based indexing)
    void insert(int val, int pos)
    {
        if(pos == 0)
        {
            push_front(val);
            return;
        }

        Node* newNode = new Node(val);

        Node* temp = head;

        for(int i = 0; i < pos-1; i++)
        {
            temp = temp->next;
        }

        // Insert at end
        if(temp == tail)
        {
            tail->next = newNode;
            tail = newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Pop Front
    void pop_front()
    {
        if(head == NULL)
        {
            cout << "List is Empty!" << endl;
            return;
        }

        if(head == tail)
        {
            delete head;
            head = tail = NULL;
            return;
        }

        Node* temp = head;

        head = head->next;

        delete temp;
    }

    // Pop Back
    void pop_back()
    {
        if(head == NULL)
        {
            cout << "List is Empty!" << endl;
            return;
        }

        if(head == tail)
        {
            delete head;
            head = tail = NULL;
            return;
        }

        Node* temp = head;

        while(temp->next != tail)
        {
            temp = temp->next;
        }

        delete tail;

        tail = temp;

        tail->next = NULL;
    }

    // Search
    int search(int key)
    {
        Node* temp = head;

        int index = 0;

        while(temp != NULL)
        {
            if(temp->data == key)
            {
                return index;
            }

            temp = temp->next;
            index++;
        }

        return -1;
    }

    // Print Linked List
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

// =======================
// Main Function
// =======================

int main()
{
    List ll;

    cout << "Push Back:" << endl;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.print();

    cout << endl;

    cout << "Push Front:" << endl;
    ll.push_front(0);
    ll.print();

    cout << endl;

    cout << "Insert 4 at Position 2:" << endl;
    ll.insert(4,2);
    ll.print();

    cout << endl;

    cout << "Search 4 :" << endl;
    cout << ll.search(4) << endl;

    cout << "Search 10 :" << endl;
    cout << ll.search(10) << endl;

    cout << endl;

    cout << "Pop Front:" << endl;
    ll.pop_front();
    ll.print();

    cout << endl;

    cout << "Pop Back:" << endl;
    ll.pop_back();
    ll.print();

    return 0;
}