// Last updated: 11/5/2026, 3:48:39 PM
1class Solution {
2public:
3    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
4        ranges::sort(arr2);
5        arr2.push_back(INT_MAX);  // sentinel: some b is always >= a - d
6        auto far = [&](int a) {  // the first b >= a - d is already past a + d
7            return *ranges::lower_bound(arr2, a - d) > a + d;
8        };
9        return ranges::count_if(arr1, far);
10    }
11};