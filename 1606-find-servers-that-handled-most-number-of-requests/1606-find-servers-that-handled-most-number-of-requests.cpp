class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        // Create a custom bitset where each uint64_t represents 64 servers
        int blocks = (k + 63) / 64;
        vector<uint64_t> free_servers(blocks, ~0ULL);
        
        // Mask out the bits in the last block that exceed 'k'
        if (k % 64 != 0) {
            free_servers[blocks - 1] &= (1ULL << (k % 64)) - 1;
        }

        // pair<time_free, server_id>
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busy;
        vector<int> cnt(k, 0);

        for (int i = 0; i < arrival.size(); i++) {
            long long time = arrival[i];
            
            // Free up servers that are done processing
            while (!busy.empty() && busy.top().first <= time) {
                int server_id = busy.top().second;
                busy.pop();
                free_servers[server_id / 64] |= (1ULL << (server_id % 64)); // Set bit to 1
            }

            int id = i % k;
            int found_id = -1;

            // 1. Search from the current id to the end of the servers
            int b = id / 64;
            int offset = id % 64;
            
            // Mask out the bits before 'offset' in the current block
            uint64_t mask = free_servers[b] & (~0ULL << offset);
            
            if (mask != 0) {
                found_id = b * 64 + __builtin_ctzll(mask);
            } else {
                // Check subsequent blocks
                for (int j = b + 1; j < blocks; j++) {
                    if (free_servers[j] != 0) {
                        found_id = j * 64 + __builtin_ctzll(free_servers[j]);
                        break;
                    }
                }
            }

            // 2. If not found, wrap around and search from the beginning to 'id'
            if (found_id == -1) {
                for (int j = 0; j <= b; j++) {
                    if (free_servers[j] != 0) {
                        found_id = j * 64 + __builtin_ctzll(free_servers[j]);
                        break;
                    }
                }
            }

            // 3. If a server is available, assign the job
            if (found_id != -1 && found_id < k) {
                free_servers[found_id / 64] &= ~(1ULL << (found_id % 64)); // Mark as busy (0)
                cnt[found_id]++;
                busy.emplace(time + load[i], found_id);
            }
        }

        // Find max requests and collect the busiest servers
        int mx = *max_element(cnt.begin(), cnt.end());
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            if (cnt[i] == mx) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};