class Solution {
public:
    void calculateSpf(vector<int>& spf) {
        int n = spf.size();

        for(int i = 0; i < n; i++) {
            spf[i] = i;
        }

        for(int i = 2; i * i < n; i++) {
            if(spf[i] == i) {
                for(int j = i * i; j < n; j += i) {
                    spf[j] = min(spf[j], i);
                }
            }
        }
    }

    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());

        vector<int> spf(maxi + 1);
        calculateSpf(spf);

        unordered_map<int, int> mpp;

        auto calculate = [&](int num) {
            vector<int> factors;

            while(num > 1) {
                int p = spf[num];
                factors.push_back(p);

                while(num % p == 0) {
                    num /= p;
                }
            }

            return factors;
        };

        int l = 0;
        int ans = 2;

        for(int r = 0; r < n; r++) {
            auto factors = calculate(nums[r]);

            for(int p : factors) {
                mpp[p]++;
            }

            auto invalid = [&]() {
                for(int p : factors) {
                    if(mpp[p] > 1)
                        return true;
                }
                return false;
            };

            while(invalid()) {
                auto temp = calculate(nums[l]);

                for(int p : temp) {
                    mpp[p]--;
                }

                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};