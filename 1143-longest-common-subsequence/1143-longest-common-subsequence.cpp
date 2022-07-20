class Solution {
public:
    int dp[1001][1001];
    int n, m;
    
    int rec(string &text1, string &text2, int len1, int len2){
        if(len1==n || len2==m) return 0;
        
        if(dp[len1][len2]!=-1) return dp[len1][len2];
        
        int ans= 0;
        if(text1[len1]==text2[len2]){
            ans = 1+rec(text1, text2, len1+1, len2+1);
        }
        else{
            ans = max(rec(text1, text2, len1+1, len2), rec(text1, text2, len1, len2+1));
        }
        
        return dp[len1][len2] = ans;
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        n = text1.length();
        m = text2.length();
        
        memset(dp, -1, sizeof(dp));
        
        int res = rec(text1, text2, 0, 0);
        return res;
    }
};