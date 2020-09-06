方法1：

c++
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.empty()) return 0;
        int ans = 1, dir = 0; //dir表示下一个可加入子列的元素的增长方向，1为正方向，-1为负方向，0表示是首元素正负增长都行。
        int last = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] == last) continue;  //当前元素与之前值相同，直接跳过
            else if(nums[i] > last){  //当前元素大于之前值
                if(dir == 0 || dir == 1){
                    ++ans;  //满足增长方向的条件则加入该正增长元素
                    dir = -1;
                }
                last = nums[i];  //即使元素不满足增长方向，但该元素的负方向范围大于之前值的，因此更改之前值
            }
            else{ //原理同上
                if(dir == 0 || dir == -1){
                    ++ans;
                    dir = 1;
                }
                last = nums[i];
            }
        }
        return ans;
    }
};