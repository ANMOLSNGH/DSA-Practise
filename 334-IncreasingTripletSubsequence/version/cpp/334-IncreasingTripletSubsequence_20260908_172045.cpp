// Last updated: 9/8/2026, 5:20:45 PM
1class Solution {
2public:
3    bool increasingTriplet(vector<int>& nums) {
4        vector<int>temp;
5        temp.push_back(nums[0]);
6        for(int i = 0;i<nums.size();i++) {
7            if(temp.size()==3) return true;
8
9            if(temp.back()<nums[i]) temp.push_back(nums[i]);
10            else {
11                int indx = lower_bound(temp.begin(),temp.end(),nums[i]) - temp.begin();
12                temp[indx] = nums[i];
13            }
14        }
15        if(temp.size()==3) return true;
16        return false;
17    }
18};