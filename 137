
方法1：
使用位运算解决问题！！！
若数a出现一次则保存在ones中，twos为0。出现两次则保存再来twos中，ones为0。出现三次则都清零
c++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for(auto &num : nums){
            ones = ones ^ num & ~twos;
            twos = twos ^ num & ~ones;
        }
        return ones;
    }
};