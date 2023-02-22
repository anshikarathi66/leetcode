//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
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
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        // code here
        //1. reverse
        head = reverse(head);
        Node* temp = new Node(1);
     
        //2. add
        Node* ans = add(head,temp);
        
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
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends