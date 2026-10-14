// Last updated: 10/14/2026, 6:14:27 PM
1class Solution {
2public:
3    int resilientSubarray(vector<int>& nums, int k) {
4        int n = nums.size();
5        int maxi_ans = 0;
6        
7        int i = 0;
8        while (i < n) {
9            long long rem = nums[i] % k;
10            int start = i;
11            
12            while (i < n && nums[i] % k == rem) {
13                i++;
14            }
15            
16            long long total = i - start;
17            
18            if (rem == 0) {
19                maxi_ans = max(maxi_ans, (int)total);
20            } 
21            else {
22                long long total_sum = total * rem; 
23                long long lcmi = lcm(rem, (long long)k);
24                
25                long long maxi_sum = (total_sum / lcmi) * lcmi;
26                long long maxi_num = 0;
27                
28                if (maxi_sum == total_sum) {
29                    maxi_sum -= lcmi;
30                    if (maxi_sum >= 0) {
31                        maxi_num = maxi_sum / rem;
32                        maxi_num++;
33                    }
34                }
35                else if (maxi_sum >= 0) {
36                    maxi_num = maxi_sum / rem;
37                    maxi_num++;
38                }
39                
40                maxi_ans = max(maxi_ans, (int)maxi_num);
41            }
42        }
43        
44        return maxi_ans;
45    }
46};