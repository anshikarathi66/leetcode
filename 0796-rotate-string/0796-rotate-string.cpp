class Solution {
public:
    bool rotateString(string s, string goal) {
//         map<char,char> mp;
        
//         if(s.length() != goal.length()){
//             return false;
//         }
        
//         for(int i=0;i<goal.length()-1;i++){
//             mp[goal[i]] = goal[i+1];
//         }
        
//         mp[goal[goal.length()-1]] = goal[0];
        
//         for(int i=0;i<s.length()-1;i++){
//             if(mp[s[i]] == s[i+1]){
//                 continue;
//             }
//             else{
//                 return false;
//             }
//         }
        
//         if(mp[s[s.length()-1]] == s[0]){
//             return true;
//         }
//         else{
//             return false;
//         }
        
        return (s.length() == goal.length() && (s+s).find(goal) != string::npos);
    }
    
};