class Solution {
public:
    int n;
    int dp[100100];
    int done[100100];
    
    int rec(int level , vector<int> &nums){
        //pruning
        
        
        //base case
        if(level==0) return nums[level];
        
        //cache check
        if(done[level]) return dp[level];
        
        //transition
        int ans = -1e9;
        ans = max(nums[level], rec(level-1, nums)+nums[level]);
        
        //save and return
        done[level]=  1;
        return dp[level] = ans;
    }
    int maxSubArray(vector<int>& nums) {
        n = nums.size();
        
        for(int i=0;i<=n;i++){
            dp[i] = -1;
        }
        
        int res = -1e9;
        
        for(int i=0;i<n;i++){
            res = max(res, rec(i, nums));
        }

        return res;
    }
};