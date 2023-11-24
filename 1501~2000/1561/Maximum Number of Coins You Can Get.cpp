class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int n = piles.size(), ans = 0;
        for(int i = 0;i < n / 3;i ++)
            ans += piles[n - i * 2 - 2];
        return ans;
    }
};
