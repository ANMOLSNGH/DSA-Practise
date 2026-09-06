#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    typedef long long ll;
    
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        int k = n / 2; // Fixed window size
        ll total_sum = accumulate(nums.begin(), nums.end(), 0LL);
        ll sum = 0;
        int cnt = 0;

        // 1. Calculate the sum of the first window [0 ... k-1]
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }

        // Check the first window
        if (sum > total_sum - sum) cnt++;

        // 2. Slide the window exactly n - 1 times
        for (int i = 1; i < n; i++) {
            // Remove the element that falls out of the window's left side
            sum -= nums[i - 1]; 
            
            // Add the new element entering the right side, using % n to wrap around
            sum += nums[(i + k - 1) % n]; 
            
            // Check the new window
            if (sum > total_sum - sum) cnt++;
        }

        return cnt;
    }
};