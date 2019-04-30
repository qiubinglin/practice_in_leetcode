
方法1：
重排元素的顺序。
c++
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        auto f = [](int &a, int &b) {
            string s1 = to_string(a), s2 = to_string(b);
            return s1+s2 > s2+s1; //前后组合一下看看哪种比较大
        };
        sort(nums.begin(), nums.end(), f);
        
        string ans;
        for(auto &num : nums){
            ans += to_string(num);
        }
        while(ans[0]=='0' && ans.length()>1)
            ans.erase(0,1);
        return ans;
    }
};