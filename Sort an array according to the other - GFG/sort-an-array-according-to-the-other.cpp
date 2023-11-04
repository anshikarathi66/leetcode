//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std;


// } Driver Code Ends
//User function template in C++


class Solution{
    public:
    // A1[] : the input array-1
    // N : size of the array A1[]
    // A2[] : the input array-2
    // M : size of the array A2[]
    
    //Function to sort an array according to the other array.
    vector<int> sortA1ByA2(vector<int> arr1, int N, vector<int> arr2, int M) 
    {
        //Your code here
        vector<int> rslt;
        map<int,int> mp;

        for(auto i:arr1){
            mp[i]++;
        }

        for(int i =0;i<arr2.size();i++){
            if(mp.find(arr2[i])!=mp.end()){
                auto it = mp.find(arr2[i]);
                int count = it->second;

                vector<int> v(count, arr2[i]);
                rslt.insert(rslt.end(), v.begin(), v.end());

                mp.erase(it);
            }
        }

        for(auto i:mp){
            int count = i.second;
            vector<int> v(count, i.first);
            rslt.insert(rslt.end(), v.begin(), v.end());
        }

        return rslt;
    } 
};

//{ Driver Code Starts.

int main(int argc, char *argv[]) 
{ 
	
	int t;
	
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    
	    vector<int> a1(n);
	    vector<int> a2(m);
	    
	    for(int i = 0;i<n;i++){
	        cin >> a1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> a2[i];
	    }
	    
	    Solution ob;
	    a1 = ob.sortA1ByA2(a1, n, a2, m); 
	
	   
	    for (int i = 0; i < n; i++) 
		    cout<<a1[i]<<" ";
		
	    cout << endl;
	    
	    
	}
	return 0; 
} 

// } Driver Code Ends