
方法1：
利用树的可用容量的概念，对于一棵有效的树，其子结构的可用容量大于等于0，整棵树的可用容量等于1。

c++
class Solution {
public:
    bool isValidSerialization(string preorder) {
        istringstream iss(preorder);
        int capacity = 1;
        
        string node;
        while(getline(iss, node, ',')){
            --capacity;
            
            if(capacity < 0) return false;
            
            if(node != "#") capacity += 2;
        }
        return capacity == 0;
    }
};