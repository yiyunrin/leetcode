class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> graph(n, vector<int>());
        vector<int> degree(n, 0);
        // 建圖 & 計算degree
        // out degree: +1, in degree: -1
        for(int i = 0;i < invocations.size();i ++){
            graph[invocations[i][0]].push_back(invocations[i][1]);
            degree[invocations[i][0]] ++;
            degree[invocations[i][1]] --;
        }
        // 找出所有有bug的點 & 計算總degree
        queue<int> q;
        vector<bool> bug(n, false);
        int sum_d = 0;
        q.push(k);
        bug[k] = true;
        while(!q.empty()){
            int now = q.front();
            sum_d += degree[now];
            q.pop();
            for(int i = 0;i < graph[now].size();i ++){
                if(!bug[graph[now][i]]){
                    q.push(graph[now][i]);
                    bug[graph[now][i]] = true;
                }
            }
        }
        // 因為必須要是一個graph中全部都有bug，才能把有bug的刪除
        // 總 degree=0 才能刪除
        bool all = sum_d != 0;
        vector<int> ans;
        for(int i = 0;i < n;i ++){
            if(all || !bug[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
