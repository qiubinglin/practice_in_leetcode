
方法1：
二分查找
c++
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        while(l < r){
            int mid = l+(r-l)/2;
            if(mid < nums.size()-1 && nums[mid] < nums[mid+1])
                l = mid+1;
            else
                r = mid;
        }
        return l;
    }
};