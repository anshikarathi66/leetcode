class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int expected_sum = (nums.size() * (nums.size() + 1)) / 2;

    // Calculate the actual sum
    int actual_sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        actual_sum += nums[i];
    }

    // Return the missing number
    return expected_sum - actual_sum;
    }
};