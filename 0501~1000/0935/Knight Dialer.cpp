//dp
class Solution {
public:
    int knightDialer(int n) {
        int mod = 1000000007;
        long long cnt[2][10] = {{1,1,1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1,1,1}};
        for(int i = 1;i < n;i ++){
            int now = i % 2, next = now == 0 ? 1 : 0;
            cnt[next][1] = (cnt[now][6] + cnt[now][8]) % mod;
            cnt[next][2] = (cnt[now][9] + cnt[now][7]) % mod;
            cnt[next][3] = (cnt[now][4] + cnt[now][8]) % mod;
            cnt[next][4] = (cnt[now][3] + cnt[now][9] + cnt[now][0]) % mod;
            cnt[next][5] = 0;
            cnt[next][6] = (cnt[now][0] + cnt[now][1] + cnt[now][7]) % mod;
            cnt[next][7] = (cnt[now][6] + cnt[now][2]) % mod;
            cnt[next][8] = (cnt[now][1] + cnt[now][3]) % mod;
            cnt[next][9] = (cnt[now][4] + cnt[now][2]) % mod;
            cnt[next][0] = (cnt[now][4] + cnt[now][6]) % mod;
        }
        long long ans = 0;
        for(int i = 0;i < 10;i ++)
            ans += cnt[n % 2][i];
        return ans % mod;
    }
};
