class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            unordered_map<int,int> mpp;
            vector<int> cnt(1501, 0);
            
            int next_stair = 1; 
            
            for(int j = i; j < n; j++) { 
                
                if(mpp.find(nums[j]) != mpp.end()) {
                    int stair_ = mpp[nums[j]];
                    cnt[stair_]++;
                    
                    if(cnt[stair_] > stair_) {
                        break; 
                    }
                }
                else {
                   mpp[nums[j]] = next_stair;
                   cnt[next_stair]++;
                   next_stair++;
                }
                
                long long k = mpp.size();
                long long expected_len = (k * (k + 1)) / 2;
                
                int current_len = j - i + 1;
                if(current_len == expected_len) {
                    ans++;
                }
            }
        }
        return ans;
    }
};