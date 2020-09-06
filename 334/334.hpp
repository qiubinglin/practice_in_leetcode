
方法1：

c++
(from alveko)
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int c1 = INT_MAX, c2 = INT_MAX;
        
        for(auto &i : nums){
            if(i <= c1) c1 = i;  // 保存最小的
            else if(i <= c2) c2 = i;  // 比c1大的最小
            else return true;  //到这里时已经有c1 < c2 < i了
        }
        return false;
    }
};