//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;


string reverseWord(string str);


int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	string s;
	cin >> s;
	
	cout << reverseWord(s) << endl;
	}
	return 0;
	
}


// } Driver Code Ends


//User function Template for C++
void swapchar(char& a,char& b){
    char temp=a;
    a=b;
    b=temp;
}

string reverseWord(string str){
    
  //Your code here
  int n=str.size();
  for(int i=0;i<str.size()/2;i++){
      swapchar(str[i],str[n-i-1]);
  }
  
  return str;
}

