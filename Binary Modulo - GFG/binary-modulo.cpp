//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        int modulo(string s,int m)
        {
            //code here
            int num =0;
    //         for (int i = s.length() - 1; i >= 0; i--) {
    // int digit = s[i] - '0';
    // num += digit * pow(2, s.length() - 1 - i);
    for (int i = 0; i < s.length(); i++) {
        num = (num * 2 + (s[i] - '0')) % m;
    }
    return num;
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
        int m;
        cin>>s>>m;
        Solution a;
        cout<<a.modulo(s,m)<<endl;
    }
    return 0;
}
// } Driver Code Ends