use std::cmp::max;
impl Solution {
    pub fn largest_rectangle_area(heights: Vec<i32>) -> i32 {
        let n = heights.len();
        if(n == 0) {return 0;}

        let mut left: Vec<i32> = vec![-1; n];
        let mut right: Vec<i32> = vec![n as i32; n];

        for i in 1..n {
            let mut cmp: i32 = i as i32-1;
            while(cmp >= 0 && heights[i] <= heights[cmp as usize]) {
                right[cmp as usize] = i as i32;
                cmp = left[cmp as usize];
            }
            left[i] = cmp;
        }

        let mut maxArea: i32 = 0;
        for i in 0..n {
            maxArea = max(maxArea, heights[i]*(right[i] - left[i] - 1));
        }
        maxArea
    }
}