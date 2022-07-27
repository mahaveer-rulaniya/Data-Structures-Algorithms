class Solution {
public:
    int n;
    int dp[100100];
    
    int rec(int i, vector<int> &nums){
        //pruning
        
        //base case
        if(i==n) return 0;
        
        //cache check
        if(dp[i]!=-1) return dp[i];
        
        //transition
        int ans = 0;
        int index = i+1;
        int curr = nums[i];
        int sum = nums[i];
        
        while(index < n && nums[index]==curr){
            sum+=nums[index];
            index++;
        }
        
        while(index < n && nums[index]==curr+1) index++;
        
        ans = max(rec(index, nums)+sum , rec(i+1, nums));
        
        //save and return
        return dp[i] = ans;
        
    }
    int deleteAndEarn(vector<int>& nums) {
        n = nums.size();
        
        for(int i=0;i<=n;i++) dp[i] = -1;
        
        sort(nums.begin(), nums.end());
        int res = rec(0, nums);
        return res;
    }
};