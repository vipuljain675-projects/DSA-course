#include <iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode* next;

    ListNode(int data)
    {
        val = data;
        next = NULL;
    }
};

// Merge Function
ListNode* merge2Lists(ListNode* h1, ListNode* h2)
{
    // Base Cases
    if(h1 == NULL)
        return h2;

    if(h2 == NULL)
        return h1;

    // Case 1
    if(h1->val <= h2->val)
    {
        h1->next = merge2Lists(h1->next, h2);
        return h1;
    }

    // Case 2
    else
    {
        h2->next = merge2Lists(h1, h2->next);
        return h2;
    }
}

// Print Linked List
void printLL(ListNode* head)
{
    while(head != NULL)
    {
        cout << head->val << " -> ";
        head = head->next;
    }

    cout << "NULL";
}

int main()
{
    // First List : 1->2->4
    ListNode* h1 = new ListNode(1);
    h1->next = new ListNode(2);
    h1->next->next = new ListNode(4);

    // Second List : 1->3->4
    ListNode* h2 = new ListNode(1);
    h2->next = new ListNode(3);
    h2->next->next = new ListNode(4);

    cout << "List 1 : ";
    printLL(h1);

    cout << "\nList 2 : ";
    printLL(h2);

    ListNode* ans = merge2Lists(h1, h2);

    cout << "\n\nMerged List : ";
    printLL(ans);

    return 0;
}