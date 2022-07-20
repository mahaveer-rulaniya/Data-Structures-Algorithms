class Solution {
public:
    int dp[38];
    
    int rec(int n){
        if(n==0) return 0;
        if(n==1 || n==2) return 1;
        
        if(dp[n]!=-1) return dp[n];
        
        int ans = 0;
        ans = rec(n-1)+rec(n-2)+rec(n-3);
        
        return dp[n] = ans;
    }
    
    int tribonacci(int n) {
        memset(dp, -1, sizeof(dp));
        
        return rec(n);
    }
};