// Last updated: 11/13/2026, 1:04:00 AM
1class Solution {
2public:
3    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
4        // Create a custom bitset where each uint64_t represents 64 servers
5        int blocks = (k + 63) / 64;
6        vector<uint64_t> free_servers(blocks, ~0ULL);
7        
8        // Mask out the bits in the last block that exceed 'k'
9        if (k % 64 != 0) {
10            free_servers[blocks - 1] &= (1ULL << (k % 64)) - 1;
11        }
12
13        // pair<time_free, server_id>
14        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busy;
15        vector<int> cnt(k, 0);
16
17        for (int i = 0; i < arrival.size(); i++) {
18            long long time = arrival[i];
19            
20            // Free up servers that are done processing
21            while (!busy.empty() && busy.top().first <= time) {
22                int server_id = busy.top().second;
23                busy.pop();
24                free_servers[server_id / 64] |= (1ULL << (server_id % 64)); // Set bit to 1
25            }
26
27            int id = i % k;
28            int found_id = -1;
29
30            // 1. Search from the current id to the end of the servers
31            int b = id / 64;
32            int offset = id % 64;
33            
34            // Mask out the bits before 'offset' in the current block
35            uint64_t mask = free_servers[b] & (~0ULL << offset);
36            
37            if (mask != 0) {
38                found_id = b * 64 + __builtin_ctzll(mask);
39            } else {
40                // Check subsequent blocks
41                for (int j = b + 1; j < blocks; j++) {
42                    if (free_servers[j] != 0) {
43                        found_id = j * 64 + __builtin_ctzll(free_servers[j]);
44                        break;
45                    }
46                }
47            }
48
49            // 2. If not found, wrap around and search from the beginning to 'id'
50            if (found_id == -1) {
51                for (int j = 0; j <= b; j++) {
52                    if (free_servers[j] != 0) {
53                        found_id = j * 64 + __builtin_ctzll(free_servers[j]);
54                        break;
55                    }
56                }
57            }
58
59            // 3. If a server is available, assign the job
60            if (found_id != -1 && found_id < k) {
61                free_servers[found_id / 64] &= ~(1ULL << (found_id % 64)); // Mark as busy (0)
62                cnt[found_id]++;
63                busy.emplace(time + load[i], found_id);
64            }
65        }
66
67        // Find max requests and collect the busiest servers
68        int mx = *max_element(cnt.begin(), cnt.end());
69        vector<int> ans;
70        for (int i = 0; i < k; i++) {
71            if (cnt[i] == mx) {
72                ans.push_back(i);
73            }
74        }
75
76        return ans;
77    }
78};