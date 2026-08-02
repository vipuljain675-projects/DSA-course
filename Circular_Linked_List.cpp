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
// Circular Linked List
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
            tail->next = head;
            return;
        }

        newNode->next = head;
        head = newNode;
        tail->next = head;
    }

    // =======================
    // Push Back
    // =======================

    void push_back(int val)
    {
        Node* newNode = new Node(val);

        if(head == NULL)
        {
            head = tail = newNode;
            tail->next = head;
            return;
        }

        tail->next = newNode;
        tail = newNode;
        tail->next = head;
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

        for(int i = 0; i < pos - 1 && temp != tail; i++)
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
        tail->next = head;

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

        Node* temp = head;

        while(temp->next != tail)
        {
            temp = temp->next;
        }

        temp->next = head;
        delete tail;
        tail = temp;
    }

    // =======================
    // Search
    // =======================

    int search(int key)
    {
        if(head == NULL)
            return -1;

        Node* temp = head;
        int index = 0;

        do
        {
            if(temp->data == key)
                return index;

            temp = temp->next;
            index++;

        } while(temp != head);

        return -1;
    }

    // =======================
    // Print
    // =======================

    void print()
    {
        if(head == NULL)
        {
            cout << "List is Empty!" << endl;
            return;
        }

        Node* temp = head;

        do
        {
            cout << temp->data << " -> ";
            temp = temp->next;

        } while(temp != head);

        cout << "(Back to Head)" << endl;
    }
};

// =======================
// Main Function
// =======================

int main()
{
    List cll;

    cout << "Push Back:" << endl;
    cll.push_back(1);
    cll.push_back(2);
    cll.push_back(3);
    cll.print();

    cout << endl;

    cout << "Push Front:" << endl;
    cll.push_front(0);
    cll.print();

    cout << endl;

    cout << "Insert 4 at Position 2:" << endl;
    cll.insert(4,2);
    cll.print();

    cout << endl;

    cout << "Search 4 :" << endl;
    cout << cll.search(4) << endl;

    cout << endl;

    cout << "Search 10 :" << endl;
    cout << cll.search(10) << endl;

    cout << endl;

    cout << "Pop Front:" << endl;
    cll.pop_front();
    cll.print();

    cout << endl;

    cout << "Pop Back:" << endl;
    cll.pop_back();
    cll.print();

    return 0;
}