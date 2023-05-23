class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        if (s.length() < k) {
            return s;  // Return the original string if length < k
        }
        
        //store ele and its count
        stack<pair<char,int>> st;
        st.push(make_pair(s[0], 1));
        
        for(int i=1;i<s.length();i++){
            if(!st.empty() && st.top().first == s[i]){
                st.top().second++;
                if(st.top().second == k){
                    st.pop();
                }
            }
            else{
                st.push(make_pair(s[i], 1));
            }
        }
        
        string ans;
        while(!st.empty()){
            ans+=string(st.top().second, st.top().first);
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};