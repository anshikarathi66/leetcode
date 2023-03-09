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
    ListNode* reverseKGroup(ListNode* head, int k) {
        //base case
	if(head==NULL){
		return NULL;
	}

	//step 1: reverse first k group
	ListNode* curr=head;
	ListNode* prevptr=nullptr;
	ListNode* nextptr=nullptr;
	int count=0;
        
        // check if there are at least k nodes remaining
    ListNode* temp = head;
    for (int i = 0; i < k; i++) {
        if (temp == nullptr) {
            return head;
        }
        temp = temp->next;
    }
        
	while(curr && count<k){
		nextptr=curr->next;
		curr->next=prevptr;
		// curr->prev=nextptr;
		prevptr=curr;
		curr=nextptr;
		count++;
	}
        
//         if(count < k) {
//     head->next = curr;
//     return prevptr;
// }

	//use recursive call
	if(nextptr!=NULL)
	head->next=reverseKGroup(nextptr, k);

	//return head of reversed list
	return prevptr;
    }
};