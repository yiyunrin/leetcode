class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();
        for(int i = 1;i < m;i ++){
            for(int j = 0;j < n;j ++){
                mat[i][j] += mat[i - 1][j];
            }
        }

        int l = 1, r = min(m, n);
        while(l <= r){
            int k = l + (r - l) / 2;
            if(bs(mat, k, m, n, threshold))
                l = k + 1;
            else
                r = k - 1;
        }

        return r;
    }
private:
    bool bs(vector<vector<int>> &mat, int k, int m, int n, int threshold){
        for(int i = k - 1;i < m;i ++){
            for(int j = k - 1;j < n;j ++){
                int sum = 0;
                for(int p = j - k + 1;p <= j && sum <= threshold;p ++){
                    sum += mat[i][p];
                    if(i - k >= 0)
                        sum -= mat[i - k][p];
                }
                if(sum <= threshold)
                    return true;
            }
        }
        return false;
    }
};
