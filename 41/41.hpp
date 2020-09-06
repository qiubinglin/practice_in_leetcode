// 41.缺失的第一个正数
// 时间复杂度O(n),空间O(1)

//将数组重置为nums[i] == i+1。则第一个缺失的正数即是i+1，其中nums[i] != i+1。
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; ++i)
        {
            while(nums[i] >= 1 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
            {
                swap(nums[i], nums[nums[i]-1]); //每交换一次即有一个数放到正确的位置，最多交换n次
            }
        }

        int res = n+1;
        for(int i = 0; i < n; ++i)
        {
            if(nums[i] != i+1)
            {
                res = i+1;
                break;
            }
        }
        return res;
    }
};