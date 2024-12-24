class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<vector<int>> graph1(n, vector<int>()), graph2(m, vector<int>());
        for(int i = 0;i < n - 1;i ++){
            graph1[edges1[i][0]].push_back(edges1[i][1]);
            graph1[edges1[i][1]].push_back(edges1[i][0]);
        }
        for(int i = 0;i < m - 1;i ++){
            graph2[edges2[i][0]].push_back(edges2[i][1]);
            graph2[edges2[i][1]].push_back(edges2[i][0]);
        }

        auto [_, endpoint1] = bfs(graph1, n, 0);
        auto [_, endpoint2] = bfs(graph2, m, 0);

        auto[dia1, _] = bfs(graph1, n, endpoint1);
        auto[dia2, _] = bfs(graph2, m, endpoint2);

        return max(dia1, max(dia2, (dia1 + 1) / 2 + (dia2 + 1) / 2 + 1));
    }

private:
    pair<int, int> bfs(vector<vector<int>> &graph, int n, int now){
        if(n == 0)
            return {0, 0};
        int dia = -1, point = now;
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(now);
        while(!q.empty()){
            int k = q.size();
            bool in = false;
            while(k --){
                now = q.front();
                q.pop();
                if(visited[now])
                    continue;
                visited[now] = true;
                for(int i = 0;i < graph[now].size();i ++)
                    q.push(graph[now][i]);
                in = true;
                point = now;
            }
            if(in)
                dia ++;
        }
        return {dia, point};
    }

};
