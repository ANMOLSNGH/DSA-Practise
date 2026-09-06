// Last updated: 9/6/2026, 10:39:06 AM
1class Solution {
2public:
3    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
4        vector<int>ans(n+m);
5        int i = 0,j=0;
6        int k = 0;
7        while(i<n&&j<m) {
8            if(nums1[i]>nums2[j]) {
9                ans[k++] = nums2[j++];
10            }
11            else ans[k++] = nums1[i++];
12        }
13        while(i<n) ans[k++] = nums1[i++];
14        while(j<m) ans[k++] = nums2[j++];
15        nums1 = ans;
16    } 
17};