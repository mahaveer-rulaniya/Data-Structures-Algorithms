class Solution {
public:
    int n;
    int dp[101];
    
    int rec(int i, vector<int> & nums){
        //pruning
        if(i<0) return 0;
        
        //base case
        if(i==0) return nums[i];
        
        //cache check
        if(dp[i]!=-1) return dp[i];
        
        //transition
        int ans = 0;
        ans = max( rec(i-1, nums), rec(i-2, nums)+nums[i] );
        
        //save and return 
        return dp[i] = ans;
    }
    
    int rob(vector<int>& nums) {
        n = nums.size();
        
        for(int i=0;i<n;i++){
            dp[i] = -1;
        }
        return max(rec(n-2, nums), rec(n-1, nums));
    }
};