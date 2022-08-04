class Solution {
public:
    
    int dp[501][501];
    
    int rec(int len1 , int len2, string &word1 , string &word2){
        
        //base case
        if(len1 == 0) return len2;
        if(len2 == 0) return len1;
        
        //cache check
        if(dp[len1][len2]!=-1) return dp[len1][len2];
        
        //transition
        int ans = 1e9;
        if(word1[len1-1]==word2[len2-1]){
            ans = rec(len1-1, len2-1 , word1, word2);
        }
        else{
            ans = 1+ min({rec(len1-1, len2-1 , word1, word2),
                         rec(len1-1, len2 , word1, word2),
                         rec(len1, len2-1 , word1, word2)});
        }
        
        //save and return
        return dp[len1][len2] = ans;
    }
    
    int minDistance(string word1, string word2) {
        for(int i=0;i<=word1.size();i++){
            for(int j=0;j<=word2.size();j++){
                dp[i][j] = -1;
            }
        }
        
        int res = rec(word1.size(), word2.size(), word1, word2);
        return res;
    }
};