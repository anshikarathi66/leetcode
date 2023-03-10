class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        vector<int> leftsum(nums.size());
        vector<int> rightsum(nums.size());
        vector<int> ans(nums.size());
        int sum=0;
        leftsum[0]=0;
        rightsum[nums.size()-1]=0;
        for(int i=1;i<nums.size();i++){
            sum+=nums[i-1];
            leftsum[i]=sum;
        }
        sum=0;
        for(int i=nums.size()-2;i>=0;i--){
            sum+=nums[i+1];
            rightsum[i]=sum;
        }
        
        for(int i=0;i<nums.size();i++){
            ans[i] = abs(leftsum[i] - rightsum[i]);
        }
        
        return ans;
    }
};