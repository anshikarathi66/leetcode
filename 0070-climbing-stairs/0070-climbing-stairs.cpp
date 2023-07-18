class Solution {
public:
    int solve(int n, vector<int> &dp){
        if(n<0)
            return 0;
        if(n==0)
            return 1;
        
        if(dp[n]!=-1){
            return dp[n];
        }
        
        dp[n] = solve(n-1, dp) + solve(n-2, dp);
        return dp[n];
    }
    int climbStairs(int n) {
//         //base case
//         if(n<0) //since no negative stairs exists
//             return 0;
//         if(n == 0)  //since no. of ways of going from 0th stair to 0th stair are one
//             return 1;
        
//         //recursive call
//         return climbStairs(n-1) + climbStairs(n-2); //no of ways for climbing n-1th stair
//                                                     //+ 
//                                                     //no of ways for climbing n-2th stair
//         //since at last stair it can either come from n-1th stair or n-2th stair
        
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};