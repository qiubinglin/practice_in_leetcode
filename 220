
方法1：
c++
from(lchen77)
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> comp_set;
        for(int i = 0; i < nums.size(); ++i){
            if(i > k) comp_set.erase(nums[i-k-1]);
            
            auto p = comp_set.lower_bound((long)nums[i]-t);
            if(p != comp_set.end() && *p-nums[i] <= t) return true;
            comp_set.insert(nums[i]);
        }
        return false;
    }
};