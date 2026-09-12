// Last updated: 9/12/2026, 8:18:40 PM
1class Solution {
2public:
3    int countSpecialIntegers(vector<int>& nums) {
4        int n = nums.size();
5        int ans = 0;
6        set<int>st;
7        for(int i = 0;i<n;i++) {
8            vector<int>indx;
9            indx.push_back(i);
10            if(st.find(nums[i])==st.end()) 
11            st.insert(nums[i]);
12            else continue;
13            int cnt = 0;
14            for(int j = i+1;j<n;j++) {
15                if(nums[j]==nums[i]) {
16                    cnt++;
17                    indx.push_back(j);
18                }
19                if(indx.size()>3) break;
20                
21            }
22            if(cnt==2) {
23                if(indx[2]-indx[1]==indx[1]-indx[0]) ans++;
24            }
25        }
26        return ans;
27    }
28};