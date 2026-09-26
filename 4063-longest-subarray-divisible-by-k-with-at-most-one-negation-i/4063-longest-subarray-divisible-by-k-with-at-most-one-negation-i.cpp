class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int ans = 0;
        
        for(int i = 0; i < nums.size(); i++){
            int sum = 0;
            unordered_set<int>comp;
            for(int j = i; j < nums.size(); j++){
                sum += nums[j];

                int rem = ((sum % k) + k) % k;

                if(rem == 0) ans = max(ans, j - i + 1);

                int x = (((nums[j] * 2) % k) + k) % k;
                comp.insert(x);

                if(comp.count(rem)) ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};