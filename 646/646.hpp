方法1：
贪心算法
c++
bool comp(vector<int> a, vector<int> b){
    return a[1] < b[1];
}

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        if(pairs.empty()) return 0;
        sort(pairs.begin(), pairs.end(), comp);
        int len = 0, cur_end = INT_MIN;

        for(int i = 0; i < pairs.size(); ++i){
            if(cur_end < pairs[i][0]){
                ++len;
                cur_end = pairs[i][1];
            }
        }

        return len;
    }
};