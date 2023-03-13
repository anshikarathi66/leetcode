class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int> presum(nums.size());
        vector<int> sufsum(nums.size());
        int sum=0;
        
        for(int i=0;i<nums.size();i++){
            presum[i] = sum;
            sum+=nums[i];
        }
        
        sum=0;
        for(int i=nums.size()-1;i>=0;i--){
            sufsum[i] = sum;
            sum+=nums[i];
        }
        
        vector<int> rslt;
        for(int i=0;i<nums.size();i++){
            int ans = (nums[i]*i - (presum[i])) + (sufsum[i] - (nums[i]*(nums.size()-i-1)));
            rslt.push_back(ans);
        }
        
        return rslt;
    }
};