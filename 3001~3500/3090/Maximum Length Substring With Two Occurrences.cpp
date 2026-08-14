class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size(), ans = 0, l = 0, r = 0;
        vector<int> cnt(26, 0);
        bool ok = true;
        // 用sliding window
        // 如果目前範圍符合規範，繼續加長 (r++)
        // 否則縮短 (l++)
        while(r < n){
            if(ok){
                cnt[s[r] - 'a'] ++;
                if(cnt[s[r] - 'a'] > 2)
                    ok = false;
                r ++;
            }
            else{
                if(cnt[s[l] - 'a'] > 2)
                    ok = true;
                cnt[s[l] - 'a'] --;
                l ++;
            }
            if(ok)
                ans = max(ans, r - l);
        }
        return ans;
    }
};
