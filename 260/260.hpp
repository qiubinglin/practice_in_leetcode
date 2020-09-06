
方法1：
c++
(from zhiqing_xiao)
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        diff &= -diff;
        
        vector<int> ans(2, 0);
        for(auto &num : nums){
            if((num & diff) == 0){
                ans[0] ^= num;
            }
            else{
                ans[1] ^= num;
            }
        }
        return ans;
    }
};