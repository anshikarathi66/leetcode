class Solution {
public:
    void sortColors(vector<int>& nums) {
        int index=0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0){
                swap(nums[index] , nums[i]);
                index++;
            }
        }
        
        for(int i=index;i<nums.size();i++){
            if(nums[i] == 1){
                swap(nums[index] , nums[i]);
                index++;
            }
        }
    }
};