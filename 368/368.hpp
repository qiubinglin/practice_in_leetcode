方法1：

c++
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end()); //由小到大排序
        
        int len = nums.size();
        vector<int> subLens(len, 1); //记录当前索引元素与之后的元素可以组成的最大subset长度
        vector<int> parents(len, 0); //记录当前索引元素在subset中的下一个元素的索引
        
        int maxLen = 0;
        int begIdx = 0;
        
        for(int i = len-1; i >= 0; --i){ //从大的开始
            for(int j = i+1; j < len; ++j){
                if(nums[j]%nums[i] == 0 && subLens[i] < 1+subLens[j]){ //nums[j]%nums[i] == 0说明元素j能加到subLen[i]中，subLens[i] < 1+subLens[j]说明 i 和 j 的组合会形成更长的subset
                    subLens[i] = subLens[j]+1;
                    parents[i] = j;
                }
            }
            
            if(subLens[i] > maxLen){
                maxLen = subLens[i]; //记录最大长度
                begIdx = i; //记录最大subset的起始元素
            }
        }
        
        vector<int> ans;
        for(int i = 0; i < maxLen; ++i){
            ans.push_back(nums[begIdx]);
            begIdx = parents[begIdx];
        }
        return ans;
    }
};