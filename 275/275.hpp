
方法1：

c++
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if(n == 0) return 0;
        int l = 0, r = n-1;
        int mid = 0;
        
        while(l < r){
            mid = l + (r-l)/2;
            if(citations[mid] >= n-mid){
                r = mid;
            }
            else{
                l = mid+1;
            }
        }
        return min(n-l, citations[l]);
    }
};