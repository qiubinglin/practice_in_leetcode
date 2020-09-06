
方法1
时间复杂度O(n)
c++
(from jianchao-li)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.empty()) return 0;
        int minLen = INT_MAX, sum = 0;
        int l = 0, r = 0;
        while(r < nums.size()){
            sum += nums[r++];
            while(sum >= s){
                sum -= nums[l++];
                if(sum < s){
                    minLen = min(r-l+1, minLen);
                }
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};

方法2
时间复杂度O(nlog(n))
c++
(from jianchao-li)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size(), minLen = INT_MAX;
        vector<int> sums(n+1, 0);
        for(int i = 1; i < n+1; ++i){
            sums[i] = sums[i-1] + nums[i-1];
        }
        
        for(int i = n; i > 0 && sums[i] >= s; --i){
            int j = upper_bound(sums.begin(), sums.end(), sums[i]-s) - sums.begin();
            minLen = min(minLen, i-j+1);
        }
        
        return minLen == INT_MAX ? 0 : minLen;
    }
};