
方法1：
c++
(from zhaoqiang)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int frombegin = 1, fromend = 1;
        vector<int> ans(n, 1);
        
        for(int i = 0; i < n; ++i){
            ans[i] *= frombegin;
            frombegin *= nums[i];
            ans[n-1-i] *= fromend;
            fromend *= nums[n-1-i];
        }
        return ans;
    }
};