class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        // 計算每個位置(0, 0)(i, j)矩形的總和
        for(int i = 0;i < m;i ++){
            for(int j = 0;j < n;j ++){
                int left = 0, up = 0, dia = 0;
                if(j > 0)
                    left = matrix[i][j - 1];
                if(i > 0)
                    up = matrix[i - 1][j];
                if(i > 0 && j > 0)
                    dia = matrix[i - 1][j - 1];
                matrix[i][j] = matrix[i][j] + left + up - dia;
            }
        }
        mat = matrix;
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        int left = 0, up = 0, dia = 0;
        if(col1 > 0)
            left = mat[row2][col1 - 1];
        if(row1 > 0)
            up = mat[row1 - 1][col2];
        if(row1 > 0 && col1 > 0)
            dia = mat[row1 - 1][col1 - 1];
        return mat[row2][col2] - left - up + dia;
    }
private:
    vector<vector<int>> mat;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
