class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return MinMax(piles, 0, piles.size() - 1) > 0;
    }
private:
    map<pair<int, int>, int> dp;
    int MinMax(vector<int> &piles, int st, int ed){
        if(st > ed)
            return 0;
        if(dp.find({st, ed}) != dp.end())
            return dp[{st, ed}];
        int front = piles[st] - MinMax(piles, st + 1, ed),
            tail = piles[ed] - MinMax(piles, st, ed - 1);
        dp[{st, ed}] = max(front, tail);
        return dp[{st, ed}];
    }
};
