//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define MOD 1000000007
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    
    int solveoptimal(int n){
        int prev2 = 1;
        int prev1 = 1;
        
        int ans = 0;
        for(int i=2;i<=n;i++){
            ans = (prev1 + prev2)%MOD;
            prev2 = prev1;
            prev1 = ans;
        }
        
        return prev1%MOD;
    }
    
    int countWays(int n)
    {
        // your code here
        return solveoptimal(n);
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends