#include <iostream>
#include <unordered_map>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if (head == NULL)
            return NULL;

        unordered_map<Node*, Node*> m;

        // ================= PASS 1 =================
        // Create copied nodes and next pointers

        Node* newHead = new Node(head->val);

        Node* oldTemp = head->next;
        Node* newTemp = newHead;

        m[head] = newHead;

        while (oldTemp != NULL) {

            Node* copyNode = new Node(oldTemp->val);

            m[oldTemp] = copyNode;

            newTemp->next = copyNode;

            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        // ================= PASS 2 =================
        // Copy random pointers

        oldTemp = head;
        newTemp = newHead;

        while (oldTemp != NULL) {

            newTemp->random = m[oldTemp->random];

            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        return newHead;
    }
};

// -----------------------
// Helper Function
// -----------------------

void printList(Node* head) {

    while (head != NULL) {

        cout << "Node = " << head->val << " ";

        if (head->random)
            cout << "Random = " << head->random->val;
        else
            cout << "Random = NULL";

        cout << endl;

        head = head->next;
    }
}

// -----------------------
// Driver Code
// -----------------------

int main() {

    // Creating Original List

    Node* n1 = new Node(7);
    Node* n2 = new Node(13);
    Node* n3 = new Node(11);
    Node* n4 = new Node(10);
    Node* n5 = new Node(1);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    // Random Pointers

    n1->random = NULL;
    n2->random = n1;
    n3->random = n5;
    n4->random = n3;
    n5->random = n1;

    cout << "Original List\n\n";
    printList(n1);

    Solution obj;

    Node* copiedHead = obj.copyRandomList(n1);

    cout << "\nCopied List\n\n";
    printList(copiedHead);

    return 0;
}