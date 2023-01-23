class Solution {
public:
    string reverseVowels(string s) {
        stack<char> st;
        
        for(int i = 0;i<s.length();i++){
            if(s[i] == 'a' || s[i] == 'o' || s[i] == 'u' || s[i] == 'e' || s[i] == 'i'||
              s[i] == 'A' || s[i] == 'O' || s[i] == 'U' || s[i] == 'E' || s[i] == 'I'){
                st.push(s[i]);
                s[i] = 'A';
            }
        }
        
        for(int i = 0;i<s.length();i++){
            if(s[i] == 'A'){
                s[i] = st.top();
                st.pop();
            }
        }
        
        return s;
    }
};