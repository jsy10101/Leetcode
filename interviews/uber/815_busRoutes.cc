// Time: O(M^2 * K)
// Space: O(M * K)
// Topics: BFS, queue
// Algo intuition:
//      - use BFS with bus stops as nodes
//      - make an adjacency map with key = stop and val = vector<route index>
//      - make a queue and a visited set to track the route containing source and to avoid visiting a route again
//      - for the queue part, perform bfs and check if current stop == target, return busCounts
//      - else, add nextStops to bfs level and continue until the queue is not empty
class Solution {
   public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) {
            return 0;
        }

        unordered_map<int, vector<int>> adjList;

        for (int route = 0; route < routes.size(); ++route) {
            for (auto stop : routes[route]) {
                adjList[stop].push_back(route);
            }
        }

        queue<int> q;
        unordered_set<int> vis;

        for (auto start : adjList[source]) {
            q.push(start);
            vis.insert(start);
        }

        int busCounts = 1;

        while (q.size() > 0) {
            int size = q.size();

            for (int i = 0; i < size; ++i) {
                int route = q.front();
                q.pop();

                for (auto stop : routes[route]) {
                    if (stop == target) {
                        return busCounts;
                    }

                    for (auto nextStop : adjList[stop]) {
                        if (!vis.count(nextStop)) {
                            vis.insert(nextStop);
                            q.push(nextStop);
                        }
                    }
                }
            }

            busCounts++;
        }

        return -1;
    }
};