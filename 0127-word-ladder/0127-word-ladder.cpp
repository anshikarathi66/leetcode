class Solution {
public:
    int ladderLength(string startWord, string targetWord, vector<string>& wordList) {
        set<string> s(wordList.begin(), wordList.end());
        
        queue<pair<string,int>> q;
        q.push(make_pair(startWord , 1));
        
        s.erase(startWord);
        
        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            if(word == targetWord){
                return steps;
            }
            
            for(int i =0;i<word.size();i++){
                char original = word[i];
                for(char temp = 'a' ; temp <= 'z' ; temp++){
                    word[i] = temp;
                    
                    if(s.find(word) != s.end()){
                        s.erase(word);
                        q.push({word,steps+1});
                    }
                }
                word[i] = original;
            }
        }
        
        return 0;
    }
};