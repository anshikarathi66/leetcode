class Solution {
public:
    int majorityElement(vector<int>& a) {
        sort(a.begin(), a.end());
        int start = 0,end = 0;
        
        while(end<a.size()){
            if(a[start] == a[end]){
                end++;
            }
            else{
                start = end;
            }
            
            if(end - start > a.size()/2){
                return a[start];
            }
        }
        
        return -1;
    }
};