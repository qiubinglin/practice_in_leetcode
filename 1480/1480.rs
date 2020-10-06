impl Solution {
    pub fn running_sum(nums: Vec<i32>) -> Vec<i32> {
        let mut rsum = vec![0; nums.len()];
        rsum[0] = nums[0];
        for i in 1..nums.len() {
            rsum[i] = rsum[i-1] + nums[i];
        }
        rsum
    }
}