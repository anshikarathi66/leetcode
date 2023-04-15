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
       void insertAtTail(ListNode* &ansHead, ListNode* &ansTail, int value){
        ListNode* temp=new ListNode(value);
        if(ansHead==NULL){
            ansHead=temp;
            ansTail=temp;
            return;
        }
        else{
            ansTail->next = temp;
            ansTail = temp;
            return;
        }
    }
    
//     ListNode *reverse(ListNode *head)
//     {
//         ListNode * prev = NULL;
//         ListNode * current = head;
//         ListNode * next;
//         while (current != NULL)
//         {
//             next = current->next;
//             current->next = prev;
//             prev = current;
//             current = next;
//         }
//         return prev;
//     }
    
    ListNode* add(ListNode* first, ListNode* second){
        int carry =0;
        ListNode* ansHead=NULL;
        ListNode* ansTail=NULL;
        
        while(first!=NULL || second!=NULL || carry!=0){
            int val1=0;
            if(first!=NULL)
                val1=first->val;
                
            int val2=0;
            if(second!=NULL)
                val2=second->val;
                
            int sum = val1+val2+carry;
            
            int digit = sum%10;
            insertAtTail(ansHead,ansTail, digit);
            carry = sum/10;
            
            if(first!=NULL){
                first = first->next;
            }
            if(second!=NULL){
                second = second->next;
            }
        }
        
        return ansHead;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       //1. reverse
//         l1 = reverse(l1);
//         l2 = reverse(l2);
        
        //2. add
        ListNode* ans = add(l1,l2);
        
        //3. reverse again
        // ans = reverse(ans);
        
        return ans;
    }
};