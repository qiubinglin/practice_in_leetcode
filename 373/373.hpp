方法1：
使用最小堆

c++
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        if (nums1.empty() || nums2.empty() || k <= 0)
            return result;
        auto comp = [&nums1, &nums2](pair<int, int> a, pair<int, int> b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];};  //最小堆大小比较的lambda表达式
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> min_heap(comp);
        min_heap.emplace(0, 0);
        while(k-- > 0 && min_heap.size())
        {
            auto idx_pair = min_heap.top(); min_heap.pop();  //弹出最小和的元素对
            result.push_back(vector<int>({nums1[idx_pair.first], nums2[idx_pair.second]}));  //加入结果中

            //将接下来可能是最小的元素对加到堆中
            if (idx_pair.first + 1 < nums1.size())
                min_heap.emplace(idx_pair.first + 1, idx_pair.second);
            if (idx_pair.first == 0 && idx_pair.second + 1 < nums2.size()) //idx_pair.first == 0防止重复将元素对加入堆中
                min_heap.emplace(idx_pair.first, idx_pair.second + 1);
        }
        return result;
    }
};