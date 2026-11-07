// Last updated: 11/7/2026, 9:54:55 PM
1class Solution {
2public:
3    using ll = long long;
4    /*
5    left side and right side
6    (left_side_size*median - sum_of_left side + sum_of_right_side - right_size_size*median)
7    */
8    int n,k,x;
9    ll min_ops[100001];
10    ll memo[16][100001];
11
12    ll solve(int i , int cnt)  {
13        if(cnt==k) return 0;
14
15        int subArrNeeded = k - cnt;
16        int elementNeeded = subArrNeeded*x;
17
18        int lstIndx = i + elementNeeded - 1;
19        if(lstIndx>=n) return 1e16;
20
21        if(memo[cnt][i]!=-1) return memo[cnt][i];
22
23        // took ith indx
24
25        ll res = min_ops[i] + solve(i+x,cnt+1);
26
27        res = min(res,solve(i+1,cnt));
28
29        return memo[cnt][i] = res;
30    }
31
32    long long minOperations(vector<int>& nums, int x, int k) {
33       this->n = nums.size();
34       this->x = x;
35       this->k = k;
36
37       memset(memo,-1,sizeof(memo));
38
39       multiset<int>left,right;
40
41       ll leftSum = 0 , rightSum = 0;
42       int i = 0 , j = 0;
43
44       while(j<n) {
45        if(left.size()<=right.size()) {
46            left.insert(nums[j]);
47            leftSum += nums[j];
48        }
49        else {
50            right.insert(nums[j]);
51            rightSum += nums[j];
52        }
53
54        // Balance krdo
55
56        if(!left.empty()&&!right.empty()) {
57            int leftMax = *left.rbegin();
58            int rightMin = *right.begin();
59
60            if(leftMax>rightMin) {
61                left.erase(left.find(leftMax));
62                right.erase(right.find(rightMin));
63
64                left.insert(rightMin);
65                right.insert(leftMax);
66
67                leftSum += rightMin - leftMax;
68                rightSum += leftMax - rightMin;
69            }
70        }
71
72            if(j-i+1==x) {
73                ll median  = *left.rbegin();
74                ll leftSize = left.size();
75                ll rightSize = right.size();
76
77                min_ops[i] = (leftSize*median-leftSum) + (rightSum - rightSize*median);
78
79                if(left.find(nums[i])!=left.end()) {
80                    left.erase(left.find(nums[i]));
81                    leftSum -= nums[i];
82                }
83                else {
84                    right.erase(right.find(nums[i]));
85                    rightSum -= nums[i];
86                }
87                i++;
88            }
89            
90        
91        j++;
92       }
93
94       return solve(0,0);
95        
96    }
97};