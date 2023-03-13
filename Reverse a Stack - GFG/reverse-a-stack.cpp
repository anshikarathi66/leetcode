//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void Reverse(stack<int> &St){
        //base case
        if(St.empty()){
            return;
        }
        
        int num = St.top();
        St.pop();
        
        Reverse(St);
        
        insertAtBottom(St,num);
    }
    
    void insertAtBottom(stack<int> &s, int num){
        //base case
        if(s.empty()){
            s.push(num);
            return;
        }
        
        int x = s.top();
        s.pop();
        
        insertAtBottom(s,num);
        
        s.push(x);
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends