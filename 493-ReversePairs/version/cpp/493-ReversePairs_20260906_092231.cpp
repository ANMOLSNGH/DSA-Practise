// Last updated: 9/6/2026, 9:22:31 AM
1class Solution {
2public:
3    
4    int cnt = 0;
5    void merge(int low,int mid,int high,vector<int>&nums) {
6         int n1 = mid-low+1;
7         int n2= high-mid;
8         vector<int>a(n1),b(n2);
9         for(int i = 0;i<n1;i++) a[i] = nums[i+low]; 
10         for(int j = 0;j<n2;j++) b[j] = nums[j+mid+1];
11
12         int i = n1-1;
13         int j = n2-1;
14         while(i>=0&&j>=0) {
15            if(a[i]>2LL*b[j]) {
16                cnt += j+1;
17                i--;
18            }
19            else {
20                j--;
21            }
22         }
23         
24          i = 0;
25          j = 0;
26         int k = low;
27         while(i<n1&&j<n2) {
28            if(a[i]>b[j]) {
29                nums[k++] = b[j++];
30            }
31            else {
32                nums[k++] = a[i++];
33            }
34         }
35
36         while(i<n1) nums[k++] = a[i++];
37         while(j<n2) nums[k++] = b[j++];
38
39    }
40    void ms(int low,int high,vector<int>&nums) {
41        if(low>=high) return;
42        int mid = low + (high-low)/2;
43
44        ms(low,mid,nums);
45        ms(mid+1,high,nums);
46        merge(low,mid,high,nums);
47    }
48    int reversePairs(vector<int>& nums) {
49        cnt = 0;
50         ms(0,nums.size()-1,nums);
51         return cnt;
52    }
53};