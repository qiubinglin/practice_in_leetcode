
方法1：
分治法
c++
(from Gcdofree)
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> ans;
        for(int i = 0; i < input.size(); ++i){
            char c = input[i];
            if(c == '+' || c == '-' || c == '*'){
                vector<int> ans1 = diffWaysToCompute(input.substr(0, i));
                vector<int> ans2 = diffWaysToCompute(input.substr(i+1));
                
                for(auto &n1 : ans1){
                    for(auto &n2 : ans2){
                        if(c == '+') ans.push_back(n1+n2);
                        else if(c == '-') ans.push_back(n1-n2);
                        else ans.push_back(n1*n2);
                    }
                }
            }
        }
        
        if(ans.empty()) ans.push_back(stoi(input));
        return ans;
    }
};