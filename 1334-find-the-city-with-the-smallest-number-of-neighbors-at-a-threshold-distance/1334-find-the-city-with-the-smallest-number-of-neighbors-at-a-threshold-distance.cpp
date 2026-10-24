class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> distance(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; ++i) {
            distance[i][i] = 0;  
        }

        for (const auto& edge : edges) {
            int node1 = edge[0], node2 = edge[1], dist = edge[2];
            distance[node1][node2] = dist;
            distance[node2][node1] = dist;
        }

        for (int midle = 0; midle < n; ++midle) {
            for (int source = 0; source < n; ++source) {
                for (int destination = 0; destination < n; ++destination) {
                    if (distance[source][midle] < INT_MAX && distance[midle][destination] < INT_MAX) {
                        distance[source][destination] = min(
                            distance[source][destination], distance[source][midle] + distance[midle][destination]
                        );  
                    }
                }
            }
        }

        int minimum_number = n;
        int res = -1;

        for (int source = 0; source < n; ++source) {
            int source_count = 0;
            for (int destination = 0; destination < n; ++destination) {
                if (distance[source][destination] <= distanceThreshold) {
                    ++source_count;
                }
            }

            if (source_count <= minimum_number) {  
                minimum_number = source_count;
                res = source;
            }
        }

        return res;
    }
};