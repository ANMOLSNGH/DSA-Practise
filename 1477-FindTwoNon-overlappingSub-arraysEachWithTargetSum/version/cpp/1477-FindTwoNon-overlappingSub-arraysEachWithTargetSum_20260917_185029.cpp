// Last updated: 9/17/2026, 6:50:29 PM
1constexpr int N=1e5, INF=1e9;
2int lens[N];
3class Solution {
4public:
5    static int minSumOfLengths(vector<int>& arr, int target) {
6        const int n=arr.size();
7        int prv=INF, ans=INF, sum=0;
8        for(int l=0, r=0; r<n; r++){
9            sum+=arr[r];
10            for(; sum>target; l++)
11                sum-=arr[l];
12            lens[r]=prv;
13            if (sum==target){
14                int len=r-l+1;
15                if (l>0) 
16                    ans=min(ans, len+lens[l-1]);
17                lens[r]=min(lens[r], len);
18            }
19            prv=lens[r];
20        }
21        return ans>=INF?-1:ans;
22
23    }
24};