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

        let (mut low, mut high) = (0, short.len());
        let totalLen = short.len() + long.len();

        while low <= high {
            let sx = low + (high - low) / 2;
            let lx = (short.len() + long.len()) / 2 - sx;

            let sleft = {
                if sx > 0 {
                    short[sx - 1]
                } else {
                    std::i32::MIN
                }
            };
            let sright = {
                if sx < short.len() {
                    short[sx]
                } else {
                    std::i32::MAX
                }
            };
            let lleft = {
                if lx > 0 {
                    long[lx - 1]
                } else {
                    std::i32::MIN
                }
            };
            let lright = {
                if lx < long.len() {
                    long[lx]
                } else {
                    std::i32::MAX
                }
            };

            if sleft <= lright && lleft <= sright {
                if totalLen % 2 == 0 {
                    let left = {
                        if sleft >= lleft {
                            sleft
                        } else {
                            lleft
                        }
                    };
                    let right = {
                        if sright <= lright {
                            sright
                        } else {
                            lright
                        }
                    };
                    return (left as f64 + right as f64) / 2.0;
                } else {
                    if sright <= lright {
                        return sright as f64;
                    } else {
                        return lright as f64;
                    }
                }
            }

            if sleft > lright {
                high = sx;
                continue;
            }

            if lleft > sright {
                low = sx + 1;
                continue;
            }
        }
        panic!("Wrong arrays");
    }
}