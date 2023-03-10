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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr || n <= 0) {
        return head;  // invalid input
    }

    ListNode* fast = head;
    ListNode* slow = head;
    ListNode* prev = nullptr;

    for (int i = 0; i < n; i++) {
        if (fast == nullptr) {
            return head;  // n is greater than the length of the list
        }
        fast = fast->next;
    }

    while (fast != nullptr) {
        prev = slow;
        slow = slow->next;
        fast = fast->next;
    }

    if (prev == nullptr) {
        head = slow->next;  // the first node is the one to be removed
    } else {
        prev->next = slow->next;  // remove the nth node
    }

    return head;

        
    }
};