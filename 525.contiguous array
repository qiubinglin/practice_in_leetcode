问题：给一个二进制数组，返回拥有相等数量0和1的最长子数组的长度。

方法1：O(n)
增量法
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum = 0; //表征当前0和1的数量差值
        int res = 0;
        unordered_map<int, int> sum_map; //记录sum和它对应的索引
        
        for(int i = 0; i < nums.size(); ++i){
            sum += (nums[i] == 1) ? 1 : -1;
            auto it = sum_map.find(sum);
            if(sum == 0){ //从nums[0]到nums[i]，0和1数量相等
                res = i + 1;
            }
            else if(it != sum_map.end() && res < i - it->second){ //已保存相同值的sum，当前索引与已保存索引之间的0和1数量相等
                res = i - it->second;
            }
            else if(it == sum_map.end()){ //记录sum第一次出现
                sum_map.insert({sum, i});
            }
        }
        return res;
    }
};