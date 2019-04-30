
方法1：
摩尔投票法
c++
(from oterman)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        if(nums.empty()) return ans;
        
        int candidateA = nums[0], countA = 0;
        int candidateB = nums[0], countB = 0;
        
        for(auto &num : nums){
            if(num == candidateA){
                ++countA;
                continue;
            }
            if(num == candidateB){
                ++countB;
                continue;
            }
            if(countA == 0){
                candidateA = num;
                ++countA;
                continue;
            }
            if(countB == 0){
                candidateB = num;
                ++countB;
                continue;
            }
            --countA, --countB;
        }
        
        countA = countB = 0;
        for(auto &num: nums){
            if(num == candidateA){
                ++countA;
            }
            else if(num == candidateB){
                ++countB;
            }
        }
        
        if(countA > nums.size()/3){
            ans.push_back(candidateA);
        }
        if(candidateA != candidateB && countB > nums.size()/3){
            ans.push_back(candidateB);
        }
        return ans;
    }
};