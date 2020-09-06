
方法1：
c++
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int beg = 0, end = 0;
        vector<string> ans;
        for(; end < nums.size();){
            if(end < nums.size()-1 && nums[end]+1 == nums[end+1]){
                ++end;
            }
            else{
                if(beg == end){
                    ans.push_back(to_string(nums[beg]));
                }
                else{
                    ans.push_back(to_string(nums[beg]) + "->" + to_string(nums[end]));
                }
                beg = ++end;
            }
        }
        return ans;
    }
};