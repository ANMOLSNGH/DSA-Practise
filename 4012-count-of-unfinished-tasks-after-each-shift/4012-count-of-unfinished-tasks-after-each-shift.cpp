class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n = tasks.size();
        int m = shifts.size();
        
        vector<unsigned long long> pref(n + 1, 0);
        for(int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + tasks[i];
        }
        
        vector<int> ans(m);
        unsigned long long current_time = 0;
        
        for(int i = 0; i < m; i++) {
            current_time += shifts[i];
            
            int completed = upper_bound(pref.begin(), pref.end(), current_time) - pref.begin() - 1;
            
            ans[i] = n - completed;
            
            if(completed == n) {
                current_time = 0;
            }
        }
        
        return ans;
    }
};