/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseLL(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {
            ListNode* next = curr->next;

            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return true;

        // Find the middle of the linked list
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half
        ListNode* second = reverseLL(slow);

        // Compare first half with reversed second half
        ListNode* first = head;
        ListNode* temp = second;

        while (temp != NULL) {
            if (first->val != temp->val)
                return false;

            first = first->next;
            temp = temp->next;
        }

        return true;
    }
};