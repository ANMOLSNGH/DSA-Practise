class Solution {
public:
    long long countValidSubstrings(string s) {
      int n = s.size();

      vector<int>next_a(n,n);
      vector<int>next_b(n,n);
      vector<int>next_c(n,n);

      int prev_a = n;
      int prev_b = n;
      int prev_c = n;

      for(int i = n-1;i>=0;i--) {
        if(s[i]=='a') {
            prev_a = i;
        }
        next_a[i] = prev_a;

        if(s[i]=='b') {
            prev_b = i;
        }
        next_b[i] = prev_b;

        if(s[i]== 'c') prev_c = i;

        next_c[i] = prev_c;
      }
      

      long long cnt = 0;
      for(int i = 0;i<n;i++) {
          int nxt_a = n;
          int nxt_b = n;
          int nxt_c = n;

          if(next_a[i]!=n) {
             nxt_a = next_a[i];
          }

          if(nxt_a<n) {
            if(next_b[nxt_a]!=n) nxt_b = next_b[nxt_a];
          }

          if(nxt_b<n) {
            if(next_c[nxt_b]!=n) nxt_c = next_c[nxt_b];
          }
          if(nxt_c>=n) cnt += n-i;
          else cnt += nxt_c - i;
      }
      return cnt;      
   }
};