class Solution {
public:
    int n;
    int dp[10010];
    
    int rec(int level, vector<int>&nums){
        //pruning
        if(level>n-1) return 1e9;
        
        //base case
        if(level==n-1) return 0;
        
        //cache check
        if(dp[level]!=-1) return dp[level];
        
        //transtion
        int ans = 1e9;
        
        for(int i=1;i<=nums[level];i++){            
            ans = min(ans , 1+rec(level+i , nums));
        }
        
        //save and return
        return dp[level] = ans;
        
    }
    int jump(vector<int>& nums) {
        n = nums.size();
        
        for(int i=0;i<=n;i++) dp[i] = -1;
        
        return rec(0, nums);
    }
};