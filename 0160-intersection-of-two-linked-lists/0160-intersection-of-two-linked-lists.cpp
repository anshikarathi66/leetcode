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
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        ListNode* ptr1=head1;
        ListNode* ptr2=head2;
    
        int len1=0;
        int len2=0;
    
    while(ptr1){
        ptr1=ptr1->next;
        len1++;
    }
    while(ptr2){
        ptr2=ptr2->next;
        len2++;
    }

    int diff=abs(len2-len1);
    
    ptr1=head1;
    ptr2=head2;
    while(diff--){
        if(len1>len2){
            ptr1=ptr1->next;
        }
        else{
            ptr2=ptr2->next;
        }
    }
    
    while(ptr1 && ptr2 && ptr1!=ptr2){
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    
    if(ptr1==NULL || ptr2==NULL){
        return NULL;
    }
    else{
        return ptr1;
    }
    }
};