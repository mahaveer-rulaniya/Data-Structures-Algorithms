class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n =prices.size();
        
        int currMax = 0;
        int totalMax = 0;
        
        for(int i=1;i<n;i++){
            currMax = max(0, currMax+=prices[i]-prices[i-1]);
            
            totalMax = max(totalMax, currMax);
        }
        
        return totalMax;
    }
};