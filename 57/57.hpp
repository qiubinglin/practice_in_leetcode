class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> res;
        int i = 0;

        while(i < n && intervals[i][1] < newInterval[0])
        {
            res.emplace_back(intervals[i++]);
        }
        res.emplace_back(newInterval);
        
        while(i < n && intervals[i][0] <= newInterval[1])
        {
            res.back()[0] = min(res.back()[0], intervals[i][0]);
            res.back()[1] = max(res.back()[1], intervals[i][1]);
            ++i;
        }

        while(i < n)
        {
            res.emplace_back(intervals[i++]);
        }
        return res;
    }
};