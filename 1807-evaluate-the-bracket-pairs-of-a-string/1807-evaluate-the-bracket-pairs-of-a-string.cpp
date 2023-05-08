class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> kmap;
        
        for(int i = 0 ;i<knowledge.size();i++){
            kmap[knowledge[i][0]] = knowledge[i][1];
        }
        
        string ans = "";
        for(int ch = 0;ch<s.length();ch++){
            if(s[ch] == '('){
                ch++;
                string temp = "";
                while(s[ch] != ')'){
                    temp+=s[ch];
                    ch++;
                }
                
                if(kmap.count(temp)){
                    ans+=kmap[temp];
                }else{
                    ans+='?';
                }
            }else{
                ans+=s[ch];
            }
        }
        
        return ans;
    }
};