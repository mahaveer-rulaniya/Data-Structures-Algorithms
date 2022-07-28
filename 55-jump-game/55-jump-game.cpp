class Solution {
public:
    int n;
    bool dp[10010];
    bool done[10010];
    
    bool rec(int level, vector<int> &nums){
        //pruining
        if(level>n-1) return false;
        
        //base case
        if(level==n-1) return true;
        
        //cache check
        if(done[level]!= 0) return dp[level];
        
        //transition
        for(int i=1;i<=nums[level] ; i++){
            if(rec(level+i, nums)){
                done[level] = 1;
                return dp[level] = true;
            }
        }
        
        //save and return
        done[level] = 1;
        return dp[level] = false;
        
    }
    bool canJump(vector<int>& nums) {
        n = nums.size();
        
        return rec(0, nums);
    }
};