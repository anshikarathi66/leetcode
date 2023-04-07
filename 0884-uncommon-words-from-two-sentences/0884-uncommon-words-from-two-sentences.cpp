class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> mp1;
       
        vector<string> rslt;
        
        string tempword ="";
        for(int i = 0;i<s1.length();i++){
            if(s1[i] == ' '){
                mp1[tempword]++;  
                tempword = "";
            }
            else{
                tempword+=s1[i];
            } 
        }
        
        mp1[tempword]++; //to store last word
        tempword="";
        
        for(int i = 0;i<s2.length();i++){
            if(s2[i] == ' '){
                mp1[tempword]++;  
                tempword = "";
            }
            else{
                tempword+=s2[i];
            } 
        }
        mp1[tempword]++; //to store last word
        tempword="";
        
        for(auto i:mp1){
            if(i.second == 1){
                rslt.push_back(i.first);
            }
        }
        
        return rslt;
        
    }
};