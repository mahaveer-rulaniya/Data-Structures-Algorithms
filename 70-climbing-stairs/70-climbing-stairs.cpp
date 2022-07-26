class Solution {
public:
    int dp[50];
    
    int rec(int n){
        if(n==0) return 1;
        if(n<0) return 0;
        
        if(dp[n]!=0) return dp[n];
        
        int ans = 0;
        ans = rec(n-1) + rec(n-2);
        
        return dp[n] = ans;
    }
    
    int climbStairs(int N) {
        int res = rec(N);
        return res;
    }
};