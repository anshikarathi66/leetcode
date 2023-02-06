class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(2*n);
        
        int index=0;
        for(int i=0,j=n;i<n;i++,j++){
            ans[index] = nums[i];
            ans[index+1] = nums[j];
            index+=2;
        }
          return ans;
    }
};