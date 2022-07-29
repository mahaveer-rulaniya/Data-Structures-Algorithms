class Solution {
public:
    int n;
    
    int maxScoreSightseeingPair(vector<int>& nums) {
        n = nums.size();
        int ans = -1e9;
        int maxEnd = -1e9;
        
        for(int i= n-2;i>=0;i--){
            maxEnd = max(maxEnd , nums[i+1]-i-1);
            ans = max(ans , nums[i]+i + maxEnd);
        }
        
        return ans;
    }
};