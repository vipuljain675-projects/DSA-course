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
    Node* prev;

    Node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

// =======================
// Doubly Linked List Class
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

    // =======================
    // Push Front
    // =======================

    void push_front(int val)
    {
        Node* newNode = new Node(val);

        if(head == NULL)
        {
            head = tail = newNode;
            return;
        }

        newNode->next = head;
        head->prev = newNode;

        head = newNode;
    }

    // =======================
    // Push Back
    // =======================

    void push_back(int val)
    {
        Node* newNode = new Node(val);

        if(head == NULL)
        {
            head = tail =newNode;
            return;
        }

        newNode->prev = tail;
        tail->next = newNode;

        tail = newNode;
    }

    // =======================
    // Insert at Position
    // (0-Based Indexing)
    // =======================

    void insert(int val, int pos)
    {
        if(pos == 0)
        {
            push_front(val);
            return;
        }

        Node* temp = head;

        for(int i=0; i<pos-1; i++)
        {
            temp = temp->next;
        }

        if(temp == tail)
        {
            push_back(val);
            return;
        }

        Node* newNode = new Node(val);

        newNode->next = temp->next;
        newNode->prev = temp;

        temp->next->prev = newNode;
        temp->next = newNode;
    }

    // =======================
    // Pop Front
    // =======================

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
        head->prev = NULL;

        delete temp;
    }

    // =======================
    // Pop Back
    // =======================

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

        Node* temp = tail;

        tail = tail->prev;
        tail->next = NULL;

        delete temp;
    }

    // =======================
    // Search
    // =======================

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

    // =======================
    // Print Forward
    // =======================

    void printForward()
    {
        Node* temp = head;

        while(temp != NULL)
        {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }

    // =======================
    // Print Backward
    // =======================

    void printBackward()
    {
        Node* temp = tail;

        while(temp != NULL)
        {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }

        cout << "NULL" << endl;
    }
};

// =======================
// Main Function
// =======================

int main()
{
    List dll;

    cout << "Push Back:" << endl;
    dll.push_back(1);
    dll.push_back(2);
    dll.push_back(3);
    dll.printForward();

    cout << endl;

    cout << "Push Front:" << endl;
    dll.push_front(0);
    dll.printForward();

    cout << endl;

    cout << "Insert 4 at Position 2:" << endl;
    dll.insert(4,2);
    dll.printForward();

    cout << endl;

    cout << "Search 4 :" << endl;
    cout << dll.search(4) << endl;

    cout << endl;

    cout << "Search 10 :" << endl;
    cout << dll.search(10) << endl;

    cout << endl;

    cout << "Pop Front:" << endl;
    dll.pop_front();
    dll.printForward();

    cout << endl;

    cout << "Pop Back:" << endl;
    dll.pop_back();
    dll.printForward();

    cout << endl;

    cout << "Backward Traversal:" << endl;
    dll.printBackward();

    return 0;
}