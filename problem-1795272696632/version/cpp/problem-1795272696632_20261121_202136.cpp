// Last updated: 11/21/2026, 8:21:36 PM
1class Solution {
2public:
3    int minRange(int a, int b, int c) {
4        int maxi  = max({a,b,c});
5        int mini = min({a,b,c});
6        int rem = 0;
7        if(a==maxi&&b==mini) rem = c;
8        if(a==maxi&&c==mini) rem = b;
9        if(b==maxi&&a==mini) rem = c;
10        if(b==maxi&&c==mini) rem = a;
11        if(c==maxi&&a==mini) rem = b;
12        if(c==maxi&&b==mini) rem = a;
13
14        int diff = maxi-mini;
15
16        int ans = min(diff,rem);
17        return ans;
18        
19    }
20};