class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> unique_pair_xors;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                unique_pair_xors.insert(nums[i] ^ nums[j]);
            }
        }
        
        unordered_set<int> unique_triplet_xors;
        
        for (int pair_xor : unique_pair_xors) {
            for (int k = 0; k < n; ++k) {
                unique_triplet_xors.insert(pair_xor ^ nums[k]);
            }
        }
        
        return unique_triplet_xors.size();
    }
};

