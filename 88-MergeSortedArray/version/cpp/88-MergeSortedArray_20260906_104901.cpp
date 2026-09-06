// Last updated: 9/6/2026, 10:49:01 AM
1class Solution {
2public:
3    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
4        int k = n+m-1;
5        int i = n-1;
6        int j = m-1;
7        while(i>=0&&j>=0) {
8            if(nums1[i]>nums2[j]) {
9                swap(nums1[k--],nums1[i--]);
10            }
11            else {
12                nums1[k--] = nums2[j--];
13            }
14        }
15        while(j>=0) nums1[k--] = nums2[j--];
16    }
17};