class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //KADANE'S ALGORITHM
        
        int sum = 0;
        int maxi = nums[0];
        
        for(int i=0;i<nums.size();i++){
            //step 1
            sum = sum+nums[i];
            
            //step2
            maxi=max(sum,maxi);
            
            //step3
            if(sum<0)
                sum=0;
        }
        
        return maxi;
    }
};