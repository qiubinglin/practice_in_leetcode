
方法1：
洗牌算法

c++
class Solution {
public:
    Solution(vector<int>& nums) {
        for(auto &i : nums){
            shf.push_back(i);
            org.push_back(i);
        }
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        for(int i = 0; i < shf.size(); ++i){
            shf[i] = org[i];
        }
        return shf;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int i = shf.size();
        while(i){
            int idx = rand()%i;
            swap(shf[idx], shf[--i]);
        }
        return shf;
    }
    
private:
    vector<int> shf, org;
};