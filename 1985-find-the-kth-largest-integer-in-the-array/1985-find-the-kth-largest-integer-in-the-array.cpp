class Solution {
public:
    struct Comp{
        bool operator()(string& a, string& b){
            if(a.size()!=b.size())
                return a.size()>b.size();
            return a>b;
        }
    };
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string , vector<string>, Comp> pq;
        
        for(int i =0;i<nums.size();i++){
            pq.push(nums[i]);
            
            if(pq.size()>k){
                pq.pop();
            }
        }
        
        return pq.top();
    }
};