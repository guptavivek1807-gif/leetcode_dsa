/*
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
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL)
            return NULL;

        // Step 1: Insert copied nodes after each original node.
        Node* curr = head;

        while (curr != NULL) {
            Node* copy = new Node(curr->val);

            copy->next = curr->next;
            curr->next = copy;

            curr = copy->next;
        }

        // Step 2: Set random pointers of copied nodes.
        curr = head;

        while (curr != NULL) {
            Node* copy = curr->next;

            if (curr->random != NULL)
                copy->random = curr->random->next;
            else
                copy->random = NULL;

            curr = copy->next;
        }

        // Step 3: Separate original and copied lists.
        curr = head;
        Node* copyHead = head->next;

        while (curr != NULL) {
            Node* copy = curr->next;

            curr->next = copy->next;

            if (copy->next != NULL)
                copy->next = copy->next->next;
            else
                copy->next = NULL;

            curr = curr->next;
        }

        return copyHead;
    }
};