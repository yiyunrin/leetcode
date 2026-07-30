class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size(), div = n / 8;
        int cnt = (1 + div) * div / 2 * 8;
        return cnt + (n & 7) * (div + 1);
    }
};
