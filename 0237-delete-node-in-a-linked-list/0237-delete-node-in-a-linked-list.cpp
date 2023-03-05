/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        //1. create temp var pointing to next of the node we want to dlt
        ListNode* nextNode=node->next;
        //2. copy val of nextnode to node we want to dlt
        node->val = nextNode->val;
        node->next = nextNode->next;
        
        //3. delete nextnode
        nextNode->next=NULL;
        delete(nextNode);
    }
};