// Last updated: 11/24/2026, 12:09:08 PM
1class Solution {
2public:
3    void calculateSpf(vector<int>& spf) {
4        int n = spf.size();
5
6        for(int i = 0; i < n; i++) {
7            spf[i] = i;
8        }
9
10        for(int i = 2; i * i < n; i++) {
11            if(spf[i] == i) {
12                for(int j = i * i; j < n; j += i) {
13                    spf[j] = min(spf[j], i);
14                }
15            }
16        }
17    }
18
19    int maxLength(vector<int>& nums) {
20        int n = nums.size();
21        int maxi = *max_element(nums.begin(), nums.end());
22
23        vector<int> spf(maxi + 1);
24        calculateSpf(spf);
25
26        unordered_map<int, int> mpp;
27
28        auto calculate = [&](int num) {
29            vector<int> factors;
30
31            while(num > 1) {
32                int p = spf[num];
33                factors.push_back(p);
34
35                while(num % p == 0) {
36                    num /= p;
37                }
38            }
39
40            return factors;
41        };
42
43        int l = 0;
44        int ans = 2;
45
46        for(int r = 0; r < n; r++) {
47            auto factors = calculate(nums[r]);
48
49            for(int p : factors) {
50                mpp[p]++;
51            }
52
53            auto invalid = [&]() {
54                for(int p : factors) {
55                    if(mpp[p] > 1)
56                        return true;
57                }
58                return false;
59            };
60
61            while(invalid()) {
62                auto temp = calculate(nums[l]);
63
64                for(int p : temp) {
65                    mpp[p]--;
66                }
67
68                l++;
69            }
70
71            ans = max(ans, r - l + 1);
72        }
73
74        return ans;
75    }
76};