class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        vector<uint> pre(n, 0), now(n, 0);
        for(int i = 0;i < n;i ++){
            if(i > 0)
                pre[i] = pre[i - 1];
            if(s[i] == t[0])
                pre[i] ++;
        }
        for(int i = 1;i < t.size();i ++){
            for(int j = i;j < n;j ++){
                now[j] = now[j - 1];
                if(s[j] == t[i])
                    now[j] += pre[j - 1];
            }
            pre = now;
            now = vector(n, (uint)0);
        }
        return pre[n - 1];
    }
};
