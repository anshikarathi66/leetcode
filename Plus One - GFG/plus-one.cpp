//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<int> increment(vector<int> digits ,int n) {
        // code here

        int lastdigit = digits[n-1];
        int index = 0;
        if(lastdigit < 9){
            digits[n-1]++;
            return digits;
        }
        else{
            for(index = n-1;(index>=0) && (digits[index]==9);index--){
                digits[index] = 0;
            }
            if(index<0){
                digits.insert(digits.begin(), 1);
            }
            else{
                digits[index]++;
            }

            return digits;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        char c;
        
        cin>>N;
        vector<int> arr(N);
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        vector<int> res = ob.increment(arr,N);
        for(int i: res)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends