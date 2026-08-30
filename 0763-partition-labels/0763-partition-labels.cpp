class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>last_seen(26,0);
        int n = s.size();
        for(int i = 0;i<s.size();i++) {
            last_seen[s[i]-'a'] = i;
        }
        int block_start = 0;
        int max_indx_seen = 0;
        vector<int>ans;
        for(int i = 0;i<n;i++) {
            int q_indx = last_seen[s[i]-'a'];

            max_indx_seen = max(max_indx_seen,q_indx);
            if(i==max_indx_seen) {
                int partition = max_indx_seen - block_start + 1;
                ans.push_back(partition);
                block_start = i + 1;
            }
        }
        return ans;
    }
};