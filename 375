方法1：

c++
class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0)); //dp[i][j]表示从i到j所需花费的最少费用，对i>j的均为0
        
        //从dp[j][i]依靠于dp[n][m]，n >= j, m <= i。因此迭代顺序如下
        for(int i = 1; i <= n; ++i){ 
            for(int j = i-1; j >= 1; j--){
                int minValue = INT_MAX;
                for(int k = j; k <= i; ++k){
                    int tmp = k + max(dp[j][k-1], dp[k+1][i]);  //若猜了k，则花费为k + 某侧的最大花费
                    minValue = min(tmp, minValue);
                }
                dp[j][i] = minValue;
            }
        }
        return dp[1][n];
    }
};