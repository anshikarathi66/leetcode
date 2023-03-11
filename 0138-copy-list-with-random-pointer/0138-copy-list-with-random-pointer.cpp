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
    void insertAtTail(Node* &head,Node* &tail,int val){
        Node* temp=new Node(val);
        
        //if linked list is empty
        if(head==NULL){
            head=temp;
            tail=temp;
        }
        //not empty
        else{
            tail->next=temp;
            tail=temp;
        }
    }
    
    Node* copyRandomList(Node* head) {
        Node* cloneHead=NULL;
        Node* cloneTail=NULL;
        Node* original=head;
        //step1. copy all nodes val and next pointer
        while(original){
            insertAtTail(cloneHead,cloneTail,original->val);
            original=original->next;
        }
        
        original=head;
        Node* clone=cloneHead;
        //step2. copy all random pointer by mapping
        unordered_map<Node* , Node*> oldToNew;
        while(original){
            oldToNew[original] = clone;
            original=original->next;
            clone=clone->next;
        }
        
        clone=cloneHead;
        original=head;
        
        while(clone){
            clone->random = oldToNew[original->random];
            clone=clone->next;
            original=original->next;
        }
        
        return cloneHead;
        
    }
};