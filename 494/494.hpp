class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return (sum<S || (sum+S)&1) ? 0 : subset_sum(nums, (sum+S)>>1);
    }
    
    int subset_sum(vector<int> &nums, int target){
        int dp[target+1] = {0};
        dp[0] = 1;
        for(int n : nums){
            for(int i = target; i >= n; --i){
                dp[i] += dp[i-n];
            }
        }
        return dp[target];
    }
};