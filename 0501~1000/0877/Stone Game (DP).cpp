class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<int> pre = piles;
        for(int i = 1;i < n;i ++){
            vector<int> tmp(n, 0);
            for(int j = 0;j + i < n;j ++){
                int st = j, ed = j + i;
                int front = piles[st] - pre[st + 1],
                    tail = piles[ed] - pre[st];
                tmp[st] = max(front, tail);
            }
            pre = tmp;
        }
        return pre[0] > 0;
    }
};
