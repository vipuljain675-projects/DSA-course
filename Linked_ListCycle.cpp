#include <iostream>
using namespace std;

// ----------------------
// Definition for singly-linked list.
// ----------------------
struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int x)
    {
        val = x;
        next = NULL;
    }
};

// ======================================================
// LeetCode 141 : Linked List Cycle
// ======================================================

class Solution141
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                return true;
            }
        }

        return false;
    }
};

// ======================================================
// LeetCode 142 : Linked List Cycle II
// ======================================================

class Solution142
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        // Step 1 : Detect Cycle
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                // Step 2 : Find Starting Node
                ListNode *entry = head;

                while (entry != slow)
                {
                    entry = entry->next;
                    slow = slow->next;
                }

                return entry;
            }
        }

        return NULL;
    }
};

int main()
{
    // For LeetCode, only the Solution classes are needed.
    // main() is kept empty so this file compiles in VS Code.

    return 0;
}