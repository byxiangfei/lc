// find the Kth (nums[K-1])
// note that, here can't use &, due to the erase functions.
double findK(vector<int> nums1, vector<int> nums2, int k) {
    int len1 = nums1.size();
    int len2 = nums2.size();
    if(len1 > len2) return findK(nums2, nums1, k);
    if(len1 == 0) return nums2[k-1];
    if(k == 1) return min(nums1[0], nums2[0]);  // 判断的是k 为1 的情况
    int pa = min(k/2, len1);
    int pb = k - pa;

    if(nums1[pa-1] < nums2[pb-1]) {
        nums1.erase(nums1.begin(), nums1.begin() + pa);
        return findK(nums1,  nums2,  k - pa);
    } else {
        nums2.erase(nums2.begin(), nums2.begin() + pb) ;
        return findK(nums1,  nums2,  k - pb);
    }
    return 0;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    if((m+n)%2) return findK(nums1,  nums2,  (m+n)/2 + 1);
    return (findK(nums1, nums2,  (m+n)/2) + findK(nums1,  nums2,  (m+n)/2+1)) / 2.0;
}
