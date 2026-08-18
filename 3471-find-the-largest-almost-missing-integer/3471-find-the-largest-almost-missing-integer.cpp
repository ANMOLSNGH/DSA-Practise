class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int,int>> visited(51); 

        int subarray = 1;
        for(int i = 0; i < n - k + 1; i++) {
            int j = i + k - 1;
            for(int s = i; s <= j; s++) {
                int val = nums[s]; 
                
                if(visited[val].first == 0) { 
                    visited[val].first = 1;
                    visited[val].second = subarray; 
                } 
                else if (visited[val].second != subarray) {
                    visited[val].first = -1; 
                }
            }
            subarray++;
        }

        for(int i = 50; i >= 0; i--) {
            if(visited[i].first == 1) return i;
        }
        return -1;
    }
};