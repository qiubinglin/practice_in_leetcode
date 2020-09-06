
方法1：
判圈算法
c++
(from echoxiaolee)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size() > 1){
            int slow = nums[0];
            int fast = nums[nums[0]];
            
            // fast步数 = slow步数 + 一圈的步数， fast步数 = slow步数 * 2
            while(slow != fast){
                slow = nums[slow];
                fast = nums[nums[fast]];
            }
            
            fast = 0;
            // fast和slow必定汇合与回环的首位
            while(slow != fast){
                slow = nums[slow];
                fast = nums[fast];
            }
            return slow;
        }
        return -1;
    }
};