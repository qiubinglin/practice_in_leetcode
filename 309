
方法1：
动态规划

c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n < 2) return 0;
        int ans = 0;
        vector<int> buy(n, 0), sell(n, 0); //buy[i]是在第i天执行买入的最大利润，sell[i]是在第i天执行卖出的最大利润。
        buy[0] = -prices[0];
        
        for(int i = 1; i < n; ++i){
            sell[i] = max(buy[i-1]+prices[i], sell[i-1]-prices[i-1]+prices[i]);
            if(ans < sell[i]) ans = sell[i];
            
            if(i == 1){
                buy[1] = -prices[1];
            }
            else{
                buy[i] = max(buy[i-1]+prices[i-1]-prices[i], sell[i-2]-prices[i]);
            }
        }
        return ans;
    }
};