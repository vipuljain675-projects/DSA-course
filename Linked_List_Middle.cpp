#include <iostream>
using namespace std;

// Definition of ListNode
class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int data) {
        val = data;
        next = NULL;
    }
};

// Insert at Tail
void insertAtTail(ListNode* &head, ListNode* &tail, int val)
{
    ListNode* newNode = new ListNode(val);

    if(head == NULL)
    {
        head = tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;
}

// Print Linked List
void printList(ListNode* head)
{
    while(head != NULL)
    {
        cout << head->val << " -> ";
        head = head->next;
    }

    cout << "NULL" << endl;
}

//-----------------------------------------------------------
// BRUTE FORCE APPROACH
//-----------------------------------------------------------
ListNode* middleNodeBrute(ListNode* head)
{
    int count = 0;
    ListNode* temp = head;

    // Count total nodes
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    int mid = count / 2;

    temp = head;

    // Move to middle
    while(mid--)
    {
        temp = temp->next;
    }

    return temp;
}

//-----------------------------------------------------------
// OPTIMAL APPROACH (FAST & SLOW POINTER)
//-----------------------------------------------------------
ListNode* middleNodeOptimal(ListNode* head)
{
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

//-----------------------------------------------------------
// MAIN FUNCTION
//-----------------------------------------------------------
int main()
{
    ListNode* head = NULL;
    ListNode* tail = NULL;

    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 5);
    insertAtTail(head, tail, 6);

    cout << "Linked List: ";
    printList(head);

    // ---------- Brute Force ----------
    ListNode* ans1 = middleNodeBrute(head);
    cout << "Middle Node (Brute Force): " << ans1->val << endl;

    // ---------- Optimal ----------
    ListNode* ans2 = middleNodeOptimal(head);
    cout << "Middle Node (Optimal): " << ans2->val << endl;

    return 0;
}