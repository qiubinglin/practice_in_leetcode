
方法1：
分治法

c++
(from james348021012)
class Solution {
public:
    int longestSubstring(string s, int k) {
        if(s.empty() || k > s.size()) return 0;
        if(k <= 1) return s.size();
        
        int counts[26] = {0};
        for(auto &c : s){
            ++counts[c-'a'];
        }
        
        int idx = 0;
        while(idx < s.size() && counts[s[idx]-'a'] >= k) ++idx;
        if(idx == s.size()) return idx;
        
        int left = longestSubstring(s.substr(0, idx), k);
        int right = longestSubstring(s.substr(idx+1), k);
        
        return max(left, right);
    }
};

(from hxtang)
int longestSubstring(string s, int k) {
    return longestSubstring_recur(s, k, 0, s.size());
}

int longestSubstring_recur(const string& s, int k, int first, int last) {
    int count[26] = {0};
    for (int j = first; j < last; ++j) ++count[s[j] - 'a'];
    
    int max_len = 0;
    for (int j = first; j < last;) {
        while (j < last && count[s[j]-'a']<k) ++j;
        if (j == last) break;
        int l = j;
        while (l < last && count[s[l]-'a']>=k) ++l;
        //all chars appear more than k times
        if (j == first && l == last) return last-first; 
        max_len = max(max_len, longestSubstring_recur(s, k, j, l));
        j = l;
    }
    return max_len;
}