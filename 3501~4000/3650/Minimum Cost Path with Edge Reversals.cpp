// Dijkstra
class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<int> ans(n, 1E9);
        vector<bool> visited(n, false);
        vector<vector<vector<int>>> graph(n, vector<vector<int>>());
        for(int i = 0;i < edges.size();i ++){
            graph[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            graph[edges[i][1]].push_back({edges[i][0], edges[i][2] * 2});
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0});
        while(!pq.empty()){
            vector<int> now = pq.top();
            pq.pop();
            if(visited[now[1]])
                continue;
            if(now[1] == n - 1)
                return now[0];
            visited[now[1]] = true;
            for(int i = 0;i < graph[now[1]].size();i ++){
                int cost = now[0] + graph[now[1]][i][1], node = graph[now[1]][i][0];
                if(ans[node] >= cost){
                    pq.push({cost, node});
                    ans[node] = cost;
                }
            }
        }
        return -1;
    }
};
