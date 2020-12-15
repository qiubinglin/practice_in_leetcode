impl Solution {
    pub fn find_median_sorted_arrays(nums1: Vec<i32>, nums2: Vec<i32>) -> f64 {
        let short;
        let long;
        if nums1.len() <= nums2.len() {
            short = nums1;
            long = nums2;
        } else {
            short = nums2;
            long = nums1;
        }

        let (mut low, mut high) = (0, short.len() - 1);

        while low <= high {
            let x = (high - low) / 2;
            let y = ()
        }
    }
}