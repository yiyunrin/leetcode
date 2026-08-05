class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        // 建圖
        vector<vector<int>> graph(n, vector<int>()), _graph(n, vector<int>());
        for(int i = 0;i < invocations.size();i ++){
            graph[invocations[i][0]].push_back(invocations[i][1]);
            // _graph[invocations[i][1]].push_back(invocations[i][0]);
        }
        // BFS找所有有bug的點
        queue<int> q;
        vector<bool> bug(n, false);
        q.push(k);
        bug[k] = true;
        while(!q.empty()){
            int now = q.front();
            q.pop();
            for(int i = 0;i < graph[now].size();i ++){
                if(!bug[graph[now][i]]){
                    q.push(graph[now][i]);
                    bug[graph[now][i]] = true;
                }
            }
        }
        // 判斷是否所有有bug的，都沒有被其他人指到
        bool all = false;
        for(int i = 0;i < invocations.size();i ++){
            if(bug[invocations[i][0]] == false && bug[invocations[i][1]] == true){
                all = true;
                break;
            }
        }
        // 如果all==true，表示不能刪除有bug的
        vector<int> ans;
        for(int i = 0;i < n;i ++){
            if(all || !bug[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
