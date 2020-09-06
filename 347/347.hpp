
方法1：
最小堆

c++
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for(auto &i : nums){
            ++count[i];
        }
        
        priority_queue<int, vector<int>, greater<int>> max_k;//最小优先队列
        for(auto &elm : count){
            max_k.push(elm.second);

            //把出现次数较小的弹出去
            while(max_k.size() > k){
                max_k.pop();
            }
        }
        
        vector<int> ans;
        for(auto &elm : count){
            if(elm.second >= max_k.top()){
                ans.push_back(elm.first);
            }
        }
        return ans;
    }
};


方法2：
桶排序

c++
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for(auto &i : nums){
            ++count[i];
        }
        
        vector<vector<int>> bucket(nums.size()+1);//创建桶，索引为出现次数、值为满足该出现次数的数集合
        
        for(auto &elm : count){
            bucket[elm.second].push_back(elm.first);
        }
        reverse(bucket.begin(), bucket.end());
        
        vector<int> ans;
        for(auto &vecn : bucket){
            for(auto &i : vecn){
                ans.push_back(i);
            }
            if(ans.size() >= k){
                return ans;
            }
        }
        return ans;
    }
};
