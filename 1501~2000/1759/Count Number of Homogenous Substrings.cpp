class Solution {
public:
    int countHomogenous(string s) {
        long long ans = 1;
        int n = s.size(), cnt = 1, mod = 1000000007;
        for(int i = 1;i < s.size();i ++){
            if(s[i] != s[i - 1])
                cnt = 1;
            else
                cnt ++;
            ans += cnt;
            ans %= mod;
        }
        return ans;
    }
};
