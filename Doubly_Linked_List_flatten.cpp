// File: FlattenMultilevelDoublyLinkedList.cpp

#include <iostream>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node(int _val) {
        val = _val;
        prev = nullptr;
        next = nullptr;
        child = nullptr;
    }
};

class Solution {
public:
    Node* flatten(Node* head) {

        // Base Case
        if (head == NULL)
            return head;

        Node* curr = head;

        while (curr != NULL) {

            // If child exists
            if (curr->child != NULL) {

                // Save next node
                Node* nextNode = curr->next;

                // Flatten the child list
                curr->next = flatten(curr->child);
                curr->next->prev = curr;

                // Remove child pointer
                curr->child = NULL;

                // Move to tail of flattened child list
                while (curr->next != NULL) {
                    curr = curr->next;
                }

                // Connect tail with original next node
                if (nextNode != NULL) {
                    curr->next = nextNode;
                    nextNode->prev = curr;
                }
            }

            // Move to next node
            curr = curr->next;
        }

        return head;
    }
};

// Function to print flattened list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    /*
        Example List

        1 - 2 - 3 - 4 - 5 - 6
                |
                7 - 8 - 9 - 10
                    |
                    11 - 12

        Expected Output:
        1 2 3 7 8 11 12 9 10 4 5 6
    */

    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);

    n1->next = n2;
    n2->prev = n1;

    n2->next = n3;
    n3->prev = n2;

    n3->next = n4;
    n4->prev = n3;

    n4->next = n5;
    n5->prev = n4;

    n5->next = n6;
    n6->prev = n5;

    Node* n7 = new Node(7);
    Node* n8 = new Node(8);
    Node* n9 = new Node(9);
    Node* n10 = new Node(10);

    n7->next = n8;
    n8->prev = n7;

    n8->next = n9;
    n9->prev = n8;

    n9->next = n10;
    n10->prev = n9;

    Node* n11 = new Node(11);
    Node* n12 = new Node(12);

    n11->next = n12;
    n12->prev = n11;

    // Child connections
    n3->child = n7;
    n8->child = n11;

    Solution obj;

    Node* ans = obj.flatten(n1);

    cout << "Flattened List: ";
    printList(ans);

    return 0;
}