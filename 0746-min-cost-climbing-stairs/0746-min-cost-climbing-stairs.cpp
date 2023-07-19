class Solution {
public:
    int solve(vector<int>& cost,int n){
        //base case
        if(n == 0){
            return cost[0];
        }
        if(n == 1){
            return cost[1];
        }
        
        return (min(solve(cost, n-1) , solve(cost , n-2)) + cost[n]);
        //adding cost[n] because instead of last step which was calculated below every other step's cost need to be added
    }
    
    int solveMem(vector<int>& cost, int n, vector<int>& dp){
        //base case
        if(n == 0){
            return cost[0];
        }
        if(n == 1){
            return cost[1];
        }
        
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n] = (min(solveMem(cost, n-1,dp) , solveMem(cost , n-2,dp)) + cost[n]);
    }
    
    int solveTab(vector<int>& cost, int n){
        vector<int> dp(n+1,-1);
        
        dp[0] = cost[0];
        dp[1] = cost[1];
        
        for(int i = 2;i<n;i++){
            dp[i] = min(dp[i-1] , dp[i-2]) + cost[i];
        }
        
        return min(dp[n-1],dp[n-2]);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();  
        // return min(solve(cost, n-1) , solve(cost , n-2)); //for last (nth) step since it doesn't need any cost to be at last step
        
        // vector<int> dp(n+1 , -1);
        // return min(solveMem(cost,n-1,dp), solveMem(cost,n-2,dp));
        
        return solveTab(cost, n);
    }
};