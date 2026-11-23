// Last updated: 11/23/2026, 10:11:30 AM
1class ProductOfNumbers {
2    vector<int> prefix{1};
3public:
4    ProductOfNumbers() {}
5
6    void add(int num) {
7        if (num == 0) prefix = {1};
8        else prefix.push_back(prefix.back() * num);
9    }
10
11    int getProduct(int k) {
12        int n = prefix.size();
13        if (k >= n) return 0;
14        return prefix[n - 1] / prefix[n - 1 - k];
15    }
16};