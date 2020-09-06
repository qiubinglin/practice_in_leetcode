
方法1：
c++
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;

        for(auto &num : nums){
            //每次循环借宿后，ans[i]表示当前以ans[i]为最大值的序列的最大长度为i+1
            auto it = lower_bound(ans.begin(), ans.end(), num);
            if(it == ans.end()) ans.push_back(num);
            else *it = num;
        }

        return ans.size();
    }
};