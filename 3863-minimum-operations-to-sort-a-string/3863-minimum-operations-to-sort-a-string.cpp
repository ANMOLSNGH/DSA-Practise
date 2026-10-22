class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int largest_indx = -1;
        int smallest_indx = -1;
        char largest_ch = 'a';
        char smallest_ch = 'z';

       if(n==2&&s[0]>s[1]) return -1;

        for(int i = 0;i<n;i++) {
              if(s[i]>=largest_ch) {
                largest_ch = s[i];
                largest_indx = i;
              }
              if(s[i]<smallest_ch) {
                smallest_ch = s[i];
                smallest_indx = i;
              }
        }

        // possible ans  = 0,1,2,3 or -1;

        // case:1 0
        string sorted  = s;
        sort(sorted.begin(),sorted.end());
        if(s==sorted) return 0;

        if(largest_indx == 0&&smallest_indx==n-1) return 3;
        if(largest_indx==n-1||smallest_indx==0) return 1;
        else return 2;


        

    }
};