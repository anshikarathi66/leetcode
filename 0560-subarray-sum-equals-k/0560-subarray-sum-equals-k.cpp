class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freqOfPrefixsum;
        int sum = 0;
        int count =0;
        
        freqOfPrefixsum[0] = 1; //freq of zero is one
        for(int i = 0 ; i < nums.size() ; i++){
            sum+=nums[i];
            if(freqOfPrefixsum.find(sum-k) != freqOfPrefixsum.end()){
                count+=freqOfPrefixsum[sum-k];
            }
            freqOfPrefixsum[sum]++;
        }
        
        return count;
    }
};