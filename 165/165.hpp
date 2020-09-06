
方法1：

c++
使用c++字符串流对象进行处理
class Solution {
public:
    int compareVersion(string version1, string version2) {
        istringstream iss1(version1), iss2(version2);
        
        while(1){
            string v1, v2;
            int n1, n2;
            if(not getline(iss1, v1, '.')) n1 = 0;
            else n1 = stoi(v1);
            
            if(not getline(iss2, v2, '.')) n2 = 0;
            else n2 = stoi(v2);
            
            if(n1 > n2) return 1;
            else if(n1 < n2) return -1;
            if(not iss1 and not iss2) return 0;
        }
    }
};