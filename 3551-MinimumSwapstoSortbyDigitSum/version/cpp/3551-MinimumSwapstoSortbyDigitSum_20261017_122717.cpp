// Last updated: 10/17/2026, 12:27:17 PM
1class Solution {
2public:
3    int getSum(int num1) {
4        int sum = 0;
5        while(num1) {
6            sum += num1%10;
7            num1 /= 10;
8        }
9        return sum;
10    }
11    int minSwaps(vector<int>& nums) {
12        int n = nums.size();
13        vector<pair<int,int>>afterSorted;
14        for(int i = 0;i<n;i++) {
15            afterSorted.push_back({nums[i],i});
16        }
17
18        auto srt = [&](pair<int,int>&n1,pair<int,int>&n2) {
19             int getSum1 = getSum(n1.first);
20             int getSum2 = getSum(n2.first);
21             if(getSum1!=getSum2) return getSum2>getSum1;
22             return n1.first<n2.first;
23        };
24        sort(afterSorted.begin(),afterSorted.end(),srt);
25        int swaps = 0;
26
27        for(int i = 0;i<n;i++) {
28            if(afterSorted[i].second==i) continue;
29            else {
30                swap(afterSorted[i], afterSorted[afterSorted[i].second]);
31                swaps++;
32                i--; 
33            }
34        }
35        return swaps;
36    }
37};