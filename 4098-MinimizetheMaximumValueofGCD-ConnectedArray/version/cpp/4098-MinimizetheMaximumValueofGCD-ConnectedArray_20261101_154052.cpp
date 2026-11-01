// Last updated: 11/1/2026, 3:40:52 PM
1class Solution {
2public:
3    int factor(int val) {
4        for(int i = 2; i * i <= val; i++) {
5            if(val % i == 0) return i;
6        }
7        return -1;
8    }
9    
10    long long minimumMaxValue(int n, int index, int value) {
11        int factor_ = factor(value);
12        long long ans = 0;
13        long long prev_;
14
15        if(value == 1) return -1;
16        
17        if(factor_ == -1) {
18            if(index != 0) return -1;
19            ans = 2LL * value + (n - 2) * 2LL; 
20        } else {
21            prev_ = value - factor_;
22            int prev_indx = index - 1;
23            long long distribute = 2LL * prev_indx; 
24            
25            if(distribute >= prev_) return -1;
26            ans = (long long)value + factor_ + (n - index - 2) * 2LL; 
27        }
28
29        return ans;
30    }
31};