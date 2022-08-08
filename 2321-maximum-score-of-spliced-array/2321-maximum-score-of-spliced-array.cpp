class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int sum1 = 0;
        int sum2 =0;
        
        for(int i=0;i<nums1.size();i++){
            sum1+=nums1[i];
            sum2+=nums2[i];
        }
        
        int currSum =0;
        int maxSum =0;
        int currSum2 =0;
        int maxSum2 =0;
        
        for(int i=0;i<nums1.size();i++){
            currSum+= nums2[i]-nums1[i];
            currSum = max(currSum , 0);
            
            currSum2+= nums1[i]-nums2[i];
            currSum2 = max(currSum2 , 0);
            
            maxSum = max(maxSum , currSum);
            maxSum2 = max(maxSum2 , currSum2);
        }
        
        int res = max( sum1+maxSum, sum2+maxSum2);
        return res;
    }
};