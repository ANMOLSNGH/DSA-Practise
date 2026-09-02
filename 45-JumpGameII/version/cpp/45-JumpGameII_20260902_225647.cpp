// Last updated: 9/2/2026, 10:56:47 PM
1class Solution {
2public:
3    int jump(vector<int>& nums) {
4        int n = nums.size();
5        int next_greater = nums[0];
6        int jumps = 0;
7        int maxi_jump_poss = 0;
8        bool laststep = false;
9        for(int i = 1;i<n;i++) {
10            maxi_jump_poss = max(maxi_jump_poss,i+nums[i]);
11
12            if(i==next_greater) {
13                if(i==n-1) laststep = true;
14                next_greater = maxi_jump_poss;
15                maxi_jump_poss = 0;
16                jumps++;
17            } 
18        }
19        if(!laststep&&n>1) jumps++;
20        return jumps;
21    }
22};