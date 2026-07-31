class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        vector<int>count(26,0);
        for(int i = 0;i<n;i++) {
            count[word[i]-'a']++;
        }

        sort(count.begin(),count.end(),greater<int>());
        int ans = 0;
        int val = 1;
        for(int i = 1;i<=26&&count[i-1]!=0;i++) {
            ans += val*count[i-1];
            if(i%8==0) val++;
        }
        return ans;
    }
};