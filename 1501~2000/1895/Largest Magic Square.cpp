class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> presum(3, vector<vector<int>>(m, vector<int>(n, 0)));
        for(int i = 0;i < m;i ++){
            for(int j = 0;j < n;j ++){
                presum[0][i][j] = presum[1][i][j] = presum[2][i][j] = grid[i][j];
                if(i > 0 && j > 0)
                    presum[0][i][j] += presum[0][i - 1][j - 1];
                if(i > 0)
                    presum[1][i][j] += presum[1][i - 1][j];
                if(j > 0)
                    presum[2][i][j] += presum[2][i][j - 1];
            }
        }
        
        for(int k = min(m, n);k >= 1;k --){
            for(int i = k - 1;i < m;i ++){
                for(int j = k - 1;j < n;j ++){
                    bool ok = true;
                    int sum = presum[0][i][j];
                    if(i >= k && j >= k)
                        sum -= presum[0][i - k][j - k];
                    for(int x = i - k + 1;x <= i && ok;x ++){
                        int tmp = presum[2][x][j];
                        if(j >= k)
                            tmp -= presum[2][x][j - k];
                        if(tmp != sum)
                            ok = false;
                    }
                    for(int y = j - k + 1;y <= j && ok;y ++){
                        int tmp = presum[1][i][y];
                        if(i >= k)
                            tmp -= presum[1][i - k][y];
                        if(tmp != sum)
                            ok = false;
                    }
                    if(ok){
                        int tmp = 0;
                        for(int l = 0;l < k;l ++){
                            tmp += grid[i - k + l + 1][j - l];
                        }
                        if(tmp != sum)
                            ok = false;
                    }
                    if(ok)
                        return k;
                }
            }
        }
        return 1;
    }
};
