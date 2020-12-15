class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	if (nums1.size() > nums2.size()) {
		swap(nums1, nums2);
	}

	int m = nums1.size(), n = nums2.size();

	int imin = 0, imax = m;
	while (imin <= imax) {
		int i = imin + (imax - imin) / 2;
		int j = (m + n + 1) / 2 - i;
		printf("i %d\n", i);
		printf("j %d\n", j);

		if (i > 0 && nums1[i - 1] > nums2[j]) {
			imax = i - 1;
		}
		else if (i < m && nums2[j - 1] > nums1[i]) {
			imin = i + 1;
		}
        else{
			if ((m + n) % 2) {
				if (i == 0)
					return nums2[j - 1];
				if (j == 0)
					return nums1[i - 1];
				return nums1[i - 1] > nums2[j - 1] ? nums1[i - 1] : nums2[j - 1];
			}
			else {
				int l = INT_MIN, r = INT_MAX;
                if(m == 0) return (nums2[j]+nums2[j-1])/2.0;
                
                if(i > 0) l = max(l, nums1[i-1]);
                if(j > 0) l = max(l, nums2[j-1]);
                if(i < m) r = min(r, nums1[i]);
                if(j < n) r = min(r, nums2[j]);
                
                return (l+r)/2.0;
			}
		}
	}
	return 0;
}
};