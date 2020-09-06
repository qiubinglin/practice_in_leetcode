
方法1:
利用快排找顺序统计量
c++
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size()-1, ans = 0;;
        while(left <= right){
            int mid = partition(nums, left, right);
            if(mid == k-1){
                ans = nums[mid];
                break;
            }
            else if(mid > k-1){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return ans;
    }
    
    int partition(vector<int>& nums, int left, int right){
        int sd = nums[right];
        int i = left, j = left;
        for(; i < right; ++i){
            if(nums[i] >= sd){
                swap(nums[i], nums[j++]);
            }
        }
        swap(nums[j], nums[right]);
        return j;
    }
};