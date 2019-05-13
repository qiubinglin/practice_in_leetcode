
方法1：
动态规划
c++
(from wyattliu)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> coinNums(amount+1, amount+1); //动态规划数组
        coinNums[0] = 0;
        
        // y元所需的最小硬币数由x元所需最小硬币数得出，其中x为小于y的数。
        for(int amo = 1; amo <= amount; ++amo){
            for(int i = 0; i < coins.size(); ++i){
                if(coins[i] <= amo){
                    coinNums[amo] = min(coinNums[amo], coinNums[amo-coins[i]]+1);
                }
            }
        }
        return coinNums[amount] <= amount ? coinNums[amount] : -1;
    }
};