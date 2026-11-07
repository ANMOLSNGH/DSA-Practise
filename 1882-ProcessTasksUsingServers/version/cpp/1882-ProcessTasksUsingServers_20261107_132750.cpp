// Last updated: 11/7/2026, 1:27:50 PM
1class Solution {
2public:
3    struct busy {
4        long long time;
5        int weight;
6        int indx;
7        
8        bool operator>(const busy& other) const {
9            if (time != other.time) return time > other.time;
10            if (weight != other.weight) return weight > other.weight;
11            return indx > other.indx;
12        }
13    };
14
15    struct free {
16        int weight;
17        int indx;
18        
19        bool operator>(const free& other) const {
20            if (weight != other.weight) return weight > other.weight;
21            return indx > other.indx;
22        }
23    };
24    
25    using Minheap = priority_queue<busy, vector<busy>, greater<busy>>;
26    using Minheap_2 = priority_queue<free, vector<free>, greater<free>>;
27    
28    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
29        Minheap b;
30        Minheap_2 f;
31        for(int i = 0; i < servers.size(); i++) f.push({servers[i], i});
32
33        vector<int> ans(tasks.size()); 
34        
35        for(int i = 0; i < tasks.size(); i++) {
36            while(!b.empty() && b.top().time <= i) {
37                f.push({b.top().weight, b.top().indx});
38                b.pop();
39            }
40            if(!f.empty()) {
41                ans[i] = f.top().indx;
42                b.push({(long long)i + tasks[i], f.top().weight, f.top().indx}); 
43                f.pop();
44            }
45            else {
46                auto top_server = b.top();
47                b.pop(); 
48                ans[i] = top_server.indx;
49                b.push({top_server.time + tasks[i], top_server.weight, top_server.indx});
50            }
51        }
52
53        return ans;
54    }
55};