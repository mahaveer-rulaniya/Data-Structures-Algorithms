class Solution {
public:
    
    int dp[1001];
    int n;
    
    int rec(int level, vector<int> &cost){
        if(level<0) return 0;
        
        if(level<=1) return cost[level];
        
        if(dp[level] !=-1) return dp[level];
        
        int ans = 0;
        ans =cost[level] + min(rec(level-1, cost), rec(level-2, cost));
    
        return dp[level] = ans;
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp, -1, sizeof(dp));
        n = cost.size();
        
        int res1 = rec(n-1,cost);
        int res2 = rec(n-2, cost);
        
        return min(res1, res2);
    }
};