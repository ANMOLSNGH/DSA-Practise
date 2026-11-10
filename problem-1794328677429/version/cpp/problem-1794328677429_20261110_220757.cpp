// Last updated: 11/10/2026, 10:07:57 PM
1class Solution {
2public:
3    bool canArrange(vector<int>& arr, int k) {
4        unordered_map<int, int> mpp;
5        for(int i = 0; i < arr.size(); i++) {
6            int rem = ((arr[i] % k) + k) % k;
7            mpp[rem]++;
8        }
9
10        if(mpp[0] % 2 != 0) return false;
11
12        for(int i = 1; i <= k / 2; i++) {
13            if(mpp[i] != mpp[k - i]) return false;
14        }
15
16        return true;
17    }
18};