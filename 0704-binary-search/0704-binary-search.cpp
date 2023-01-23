class Solution {
public:
    int solve(vector<int>& nums, int start, int end,int target){
        //base case
        if(start>end)
            return -1;
        
        int mid = start + (end-start)/2;
        
        if(nums[mid] == target)
            return mid;
        
        if(nums[mid] < target)
            return solve(nums, mid+1, end, target);
        else
            return solve(nums, start, mid-1, target);
    }
    
    int search(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        return solve(nums, 0, nums.size()-1, target );
    }
};