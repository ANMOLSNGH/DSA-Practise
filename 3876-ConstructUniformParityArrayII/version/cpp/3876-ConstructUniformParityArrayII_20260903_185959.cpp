// Last updated: 9/3/2026, 6:59:59 PM
1class Solution {
2public:
3    int findjustsmaller(vector<int>&nums,int target) {
4        int n = nums.size();
5        int low = 0;
6        int high = n-1;
7        int ans = -1;
8        while(low<=high) {
9            int mid = low + (high-low)/2;
10            if(nums[mid]>=target) {
11                high = mid-1;
12            }
13            else {
14                low = mid+1;
15                ans = nums[mid];
16            }
17        }
18        return ans;
19    }
20    bool uniformArray(vector<int>& nums1) {
21        vector<int>odd_only;
22        // vector<int>even_only;
23        int n = nums1.size();
24        for(auto num:nums1) {
25            if(num&1) odd_only.push_back(num); 
26        }
27        sort(odd_only.begin(),odd_only.end());
28        // sort(even_only.begin(),even_only.end());
29        bool all_even = true;
30        bool all_odd = true;
31       
32        // case 1 let say all are even.
33        for(auto num : nums1) {
34             if((num&1)==0) continue;
35             else {
36                int ans = findjustsmaller(odd_only,num);
37                if(ans==-1) {
38                    all_even = false;
39                    break;
40                }
41             }
42        }
43        if(all_even) return true;
44    
45        for(auto num : nums1) {
46        if(num&1) continue;
47        else {
48        int ans = findjustsmaller(odd_only,num);
49        if(ans==-1) {
50            all_odd = false;
51            break;
52           }
53        }
54      }
55      return all_odd;
56    }
57};