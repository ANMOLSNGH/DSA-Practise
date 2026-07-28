class Solution {
public:
    string smallestPalindrome(string s) {

        vector<int> freq(26, 0);

        for (char ch : s)
            freq[ch - 'a']++;

        int n = s.size();

        string ans(n, ' ');

        int left = 0;
        int right = n - 1;

        for (int i = 0; i < 26; i++) {

            while (freq[i] >= 2) {
                ans[left] = i + 'a';
                ans[right] = i + 'a';

                left++;
                right--;

                freq[i] -= 2;
            }

            if (freq[i] == 1)
                ans[n / 2] = i + 'a';
        }

        return ans;
    }
};