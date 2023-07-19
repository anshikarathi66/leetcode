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
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();  
        // return min(solve(cost, n-1) , solve(cost , n-2)); //for last (nth) step since it doesn't need any cost to be at last step
        
        vector<int> dp(n+1 , -1);
        return min(solveMem(cost,n-1,dp), solveMem(cost,n-2,dp));
    }
};