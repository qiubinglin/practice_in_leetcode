
方法1：
c++
(from zhiqing_xiao)
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int len = nums.size();
        
        //找到中位值
        auto it = next(nums.begin(), len/2);
        nth_element(nums.begin(), it, nums.end());
        int midnum = *it;
        
        auto m = [len](int idx) { return (2*idx+1) % (len|1); };//用于分别遍历奇偶索引
        int first = 0, mid = 0, last = len-1;
        
        //将小于中位值的放在last槽，大于的放在first槽，等于的放在剩余槽。
        while(mid <= last){
            int index = m(mid);
            if(nums[index] < midnum){
                swap(nums[index], nums[m(last)]);
                --last;
            }
            else if(nums[index] > midnum){
                swap(nums[index], nums[m(first)]);
                ++first;
                ++mid;
            }
            else{
                ++mid;
            }
        }
    }
};