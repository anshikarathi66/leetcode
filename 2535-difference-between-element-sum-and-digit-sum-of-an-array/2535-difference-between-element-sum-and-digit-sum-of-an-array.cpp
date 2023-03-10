class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int elementsum=0;
        for(int i=0;i<nums.size();i++){
            elementsum+=nums[i];
        }
        
        int digitSum=0;
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            int digit=0;
            while(num){
                digit=num%10;
                num/=10;
                digitSum+=digit;
            }
        }
        
        return abs(elementsum-digitSum);
    }
};