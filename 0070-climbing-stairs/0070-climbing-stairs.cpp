class Solution {
public:
    int solveMem(int n, vector<int> &dp){
        if(n<0)
            return 0;
        if(n==0)
            return 1;
        
        if(dp[n]!=-1){
            return dp[n];
        }
        
        dp[n] = solveMem(n-1, dp) + solveMem(n-2, dp);
        return dp[n];
    }
    
    int solve(int n){
        //base case
        if(n<0) //since no negative stairs exists
            return 0;
        if(n == 0)  //since no. of ways of going from 0th stair to 0th stair are one
            return 1;
        
        //recursive call
        return climbStairs(n-1) + climbStairs(n-2); //no of ways for climbing n-1th stair
                                                    //+ 
                                                    //no of ways for climbing n-2th stair
        //since at last stair it can either come from n-1th stair or n-2th stair
        
    }
    
    int solvetab(int n){
        vector<int> dp(n+1,0);
        
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i = 2;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp[n];
    }
    
    int solveoptimal(int n){
        int prev2 = 1;
        int prev1 = 1;
        
        int ans = 0;
        for(int i=2;i<=n;i++){
            ans = prev1 + prev2;
            prev2 = prev1;
            prev1 = ans;
        }
        
        return prev1;
    }
    
    int climbStairs(int n) {
        
        // return solve(n);
        
        // vector<int> dp(n+1,-1);
        // return solveMem(n,dp);
        
        // return solvetab(n);
        
        return solveoptimal(n);
    }
};