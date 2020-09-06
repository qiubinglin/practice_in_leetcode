class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        if(m*n == 0) return m+n;

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i = 0; i <= m; ++i) dp[i][0] = i;
        for(int j = 0; j <= n; ++j) dp[0][j] = j;

        for(int i = 1; i <= m; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                int x = dp[i-1][j] + 1;
                int y = dp[i][j-1] + 1;
                int z = dp[i-1][j-1];
                if(word1[i-1] != word2[j-1]) z += 1;
                dp[i][j] = min(x, min(y, z));
            }
        }
        return dp[m][n];
    }
};