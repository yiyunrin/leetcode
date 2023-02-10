class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) 
    {
        int ans = 0, count = 0, n = grid.size();
        queue<pair<int, int>> step;
        for(int i = 0;i < n;++ i)
            for(int j = 0;j < n;++ j)
                if(grid[i][j] == 1)
                {
                    step.push({i, j});
                    ++ count;
                }

        while(!step.empty() && count != n * n)
        {
            int tmp = step.size();
            ++ ans;
            for(int i = 0;i < tmp;i ++)
            {
                auto [x, y] = step.front();
                step.pop();
                for(int j = max(0, x - 1);j <= min(x + 1, n - 1);++ j)
                    for(int k = max(0, y - 1);k <= min(y + 1, n - 1);++ k)
                        if((j == x || k == y) && !grid[j][k])
                        {
                            step.push({j, k});
                            grid[j][k] = 1;
                            ++ count;
                        }
            }
        } 
        return ans == 0 ? -1 : ans;
    }
};
