
方法1：
二分搜索，找到最小的满足条件的值。

c++
(from 2997ms)
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int left = matrix[0][0], right = matrix[m-1][m-1];
        
        while(left < right){
            int mid = left + (right-left)/2;
            int num = 0; //记录矩阵中小于等于mid的元素的个数
            
            for(int i = 0; i < m; ++i){
                int pos = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
                num += pos;
            }
            
            if(num < k) left = mid+1;
            else right = mid;  //找到最小的满足条件的值。
        }
        return left;
    }
};

方法2：
最小堆

c++
(from projjal)
class Solution {
public:
struct compare
{
    bool operator()(const pair<int,pair<int, int> >& a, const pair<int,pair<int, int> >& b)
    {
        return a.first>b.first;
    }
};
    int kthSmallest(vector<vector<int>>& arr, int k) {
        
        int n=arr.size(),m=arr[0].size();
        
        priority_queue< pair<int,pair<int, int> >, vector<pair<int, pair<int, int> > >, compare > p;
        
        for(int i=0;i<n;i++)
        p.push(make_pair(arr[i][0],make_pair(i,0)));
        
        int x=k,ans;

        //把最小的k个元素弹掉
        while(x--)
        {
            //优先队列保证了首先被处理的是当前最小的元素
            int e=p.top().first;
            int i=p.top().second.first;
            int j=p.top().second.second;
            ans=e;
            p.pop();
            if(j!=m-1)
            p.push(make_pair(arr[i][j+1],make_pair(i,j+1)));  //每次弹走一个元素就把与其同一行的后继元素加进队列
        }
        return ans;
        
    }
};