class Solution {
public:
    
    int n;
    int dp[2505][2505];
    
    int rec(int level, int prev , vector<int>&nums){

        //base case
        if(level==n) return 0;
        
        //cache check
        if(dp[level][prev+1] != -1) return dp[level][prev+1];
        
        //transition 
        int ans = -1e9;
        ans = max(ans , rec(level+1, prev, nums));
        
        if(prev==-1 || nums[level]>nums[prev]){
            ans = max(ans , 1+rec(level+1, level , nums));
        }
        
        //save and return
        return dp[level][prev+1] = ans;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                dp[i][j] = -1;
            }
        }
        
        int res = rec(0, -1, nums);
        return res;
    }
};