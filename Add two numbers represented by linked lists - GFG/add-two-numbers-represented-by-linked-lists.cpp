//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    void insertAtTail(struct Node* &ansHead, struct Node* &ansTail, int val){
        Node* temp=new Node(val);
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
    
    Node *reverse(Node *head)
    {
        Node * prev = NULL;
        Node * current = head;
        Node * next;
        while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
    
    struct Node* add(struct Node* first, struct Node* second){
        int carry =0;
        Node* ansHead=NULL;
        Node* ansTail=NULL;
        
        while(first!=NULL || second!=NULL || carry!=0){
            int val1=0;
            if(first!=NULL)
                val1=first->data;
                
            int val2=0;
            if(second!=NULL)
                val2=second->data;
                
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
    
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        //1. reverse
        first = reverse(first);
        second = reverse(second);
        
        //2. add
        Node* ans = add(first,second);
        
        //3. reverse again
        ans = reverse(ans);
        
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends