class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int ans = 0, m = matrix.size(), n = matrix[0].size();
        for(int i = 0;i < m;i ++){
            for(int j = 0;j < n;j ++){
                if(matrix[i][j] == 1){
                    int mn = INT_MAX;
                    if(i > 0)
                        mn = min(mn, matrix[i - 1][j]);
                    else mn = 0;

                    if(j > 0)
                        mn = min(mn, matrix[i][j - 1]);
                    else mn = 0;

                    if(i > 0 && j > 0)
                        mn = min(mn, matrix[i - 1][j - 1]);
                    else mn = 0;
                    
                    matrix[i][j] = mn + 1;
                    ans += matrix[i][j];
                }
            }
        }
        return ans;
    }
};
