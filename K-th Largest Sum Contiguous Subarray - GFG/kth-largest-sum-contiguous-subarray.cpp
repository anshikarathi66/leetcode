//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int kthLargest(vector<int> &Arr,int N,int K){
        priority_queue<int, vector<int>, greater<int> > minheap;
        
        int a = 0;
        int b = 1;
     
        int sum = Arr[a];
        while(a < N-1){
            if(b<=N-1){
                sum = sum + Arr[b] ;
                if(minheap.size() < K){
                    minheap.push(sum);
                }
                else if(minheap.size() >= K && sum > minheap.top()){
                    minheap.pop();
                    minheap.push(sum);
                }
                b++;
            }
            else if(b==N){
                a++;
                sum = Arr[a];
                b = a+1;
            }
        }
        
        for(int i = 0; i<N;i++){
            if(minheap.size() < K){
                minheap.push(Arr[i]);
            }
            else if(minheap.size() >= K && Arr[i] > minheap.top()){
                minheap.pop();
                minheap.push(Arr[i]);
                
            }
        }
        
        return minheap.top();
    }
};

//{ Driver Code Starts.

int main(){
    
    int T;
    cin>>T;
    while(T--){
        int N,K;
        cin>>N;
        cin>>K;
        vector<int> Arr(N);
        for(int i=0;i<N;i++){
            cin>>Arr[i];
        }
        Solution ob;
        int ans=ob.kthLargest(Arr,N,K);
        cout<<ans<<endl;
    }
    return 0;
}
// } Driver Code Ends