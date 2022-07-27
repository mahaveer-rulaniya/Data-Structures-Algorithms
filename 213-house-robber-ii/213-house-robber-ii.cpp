class Solution {
public:
    int n;
    int dp[101][2];
    
    int rec(int i, vector<int> & nums , bool flag){
        //pruning
        if(i<0) return 0;
        
        //base case
        if(i==0 && flag==true) return 0;
        if(i==0 && flag==false) return nums[i];
        
        //cache check
        if(dp[i][flag]!=-1) return dp[i][flag];
        
        //transition
        int ans = 0;
        ans = max(rec(i-1, nums, flag), rec(i-2, nums, flag)+nums[i]);
        
        //save and return
        return dp[i][flag] = ans;
    }
    
    int rob(vector<int>& nums) {
        n = nums.size();
        
        for(int i=0;i<n;i++){
            for(int j = 0;j<2;j++)
                dp[i][j]= -1;
        }
        
        if(n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);
  
        int res1 = rec(n-1, nums,true);
        
        int res2 = rec(n-2, nums, false);
        
        return max(res1, res2);
    }
};