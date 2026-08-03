#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

// Solution Class
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

        // Base Case:
        // If there are 0 or 1 nodes left, no swapping is needed.
        if (head == NULL || head->next == NULL)
            return head;

        // First and second nodes of the current pair
        ListNode* first = head;
        ListNode* second = head->next;

        // Recursively swap the remaining list
        first->next = swapPairs(second->next);

        // Swap current pair
        second->next = first;

        // New head of this swapped pair
        return second;
    }
};

// Create Linked List
ListNode* createList(vector<int> arr) {

    if (arr.empty())
        return NULL;

    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;

    for (int i = 1; i < arr.size(); i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }

    return head;
}

// Print Linked List
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

    vector<int> arr = {1, 2, 3, 4, 5};

    ListNode* head = createList(arr);

    cout << "Original List:\n";
    printList(head);

    Solution obj;
    head = obj.swapPairs(head);

    cout << "After Swapping Pairs:\n";
    printList(head);

    return 0;
}