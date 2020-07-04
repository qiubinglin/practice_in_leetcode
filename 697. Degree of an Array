697.数组的度
数组的度是元素的最大出现次数，给定一个数组，返回与数组有相同度的连续子数组最小长度

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> count, first; //记录元素的次数和第一次出现的位置
        int res = 0, degree = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(first.count(nums[i]) == 0){
                first[nums[i]] = i;
            }
            ++count[nums[i]];
            if(count[nums[i]] > degree){ //当前元素出现次数最大
                degree = count[nums[i]];
                res = i - first[nums[i]] + 1;
            }
            else if(count[nums[i]] == degree){
                res = min(res, i - first[nums[i]] + 1);
            }
        }
        return res;
    }
};