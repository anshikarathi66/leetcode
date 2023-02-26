//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
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
}

Node* findIntersection(Node* head1, Node* head2);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>> n >> m;
	    
	    Node* head1 = inputList(n);
	    Node* head2 = inputList(m);
	    
	    Node* result = findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}

// } Driver Code Ends


/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

void insertAtTail(Node* &ansHead, Node* &ansTail, int val){
    Node* temp=new Node(val);
    
    //if list empty
    if(ansHead ==NULL){
        ansHead = temp;
        ansTail = temp;
        return;
    }
    //if list not empty
    else{
        ansTail->next = temp;
        ansTail  = temp;
        return;
    }
}

Node* findIntersection(Node* head1, Node* head2)
{
    // Your Code Here
    Node* a = head1;
    Node* b = head2;
    Node* ansHead = NULL;
    Node* ansTail = NULL;
    
    while(a!=NULL && b!=NULL){
        if(a->data < b->data)
            a=a->next;
            
        else if(a->data > b->data )
            b=b->next;
            
        else if(a->data == b->data ){
            insertAtTail(ansHead,ansTail,a->data);
            a=a->next;
            b=b->next;
        }
    }
    
    return ansHead;
}