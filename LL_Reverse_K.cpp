#include <iostream>
using namespace std;

// Definition for singly-linked list
class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        // ==========================
        // STEP 1: Check if k nodes exist
        // ==========================
        ListNode* temp = head;
        int cnt = 0;

        while (cnt < k) {
            if (temp == NULL)
                return head;        // Less than k nodes left

            temp = temp->next;
            cnt++;
        }

        // ==========================
        // STEP 2: Recursively reverse remaining list
        // ==========================
        ListNode* nextHead = reverseKGroup(temp, k);

        // ==========================
        // STEP 3: Reverse current k nodes
        // ==========================
        ListNode* prev = nextHead;
        ListNode* curr = head;

        for (int i = 0; i < k; i++) {
            ListNode* front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }

        return prev;
    }
};

// Function to insert node at end
void insertAtTail(ListNode*& head, int val) {
    ListNode* newNode = new ListNode(val);

    if (head == NULL) {
        head = newNode;
        return;
    }

    ListNode* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Function to print linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val;
        if (head->next != NULL)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    ListNode* head = NULL;

    // Create Linked List: 1->2->3->4->5->6->7->8
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    insertAtTail(head, 7);
    insertAtTail(head, 8);

    int k = 3;

    cout << "Original List:\n";
    printList(head);

    Solution obj;
    head = obj.reverseKGroup(head, k);

    cout << "\nAfter Reversing in Groups of " << k << ":\n";
    printList(head);

    return 0;
}