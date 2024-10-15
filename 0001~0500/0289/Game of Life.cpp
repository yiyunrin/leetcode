class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> now = board;
        m = board.size(), n = board[0].size();
        for(int i = 0;i < m;i ++)
            for(int j = 0;j < n;j ++)
                board[i][j] = next(i, j, now);
    }
private:
    int m, n;
    int next(int x, int y, vector<vector<int>> &board){
        int cnt = -1 * board[x][y];
        for(int i = max(0, x - 1);i <= min(m - 1, x + 1);i ++)
            for(int j = max(0, y - 1);j <= min(n - 1, y + 1);j ++)
                cnt += board[i][j];
        if(board[x][y] == 1 && (cnt == 2 || cnt == 3))
            return 1;
        if(board[x][y] == 0 && cnt == 3)
            return 1;
        return 0;
    }
};
