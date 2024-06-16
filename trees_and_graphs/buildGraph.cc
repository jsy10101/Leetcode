unordered_map<int, vector<int>> buildGraph(vector<vector<int>>& edges) {
    unordered_map<int, vector<int>> graph;
    for (vector<int>& edge: edges) {
        int x = edge[0], y = edge[1];
        graph[x].push_back(y);
        // graph[y].push_back(x);
        // uncomment the above line if the graph is undirected
    }
    
    return graph;
}
