class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> cnt(26, 0);
        int n = s.size();
        // 用counting sort，先計算每個字母有多少個
        for(int i = 0;i < n;i ++){
            cnt[s[i] - 'a'] ++;
        }
        int now = 0;
        // 再依序把字幕由小到大放到s中
        for(int i = 0;i < 26;i ++){
            char c = 'a' + i;
            // 如果大於2個，就會兩兩放到s的頭尾
            for(int j = 2;j <= cnt[i];j += 2){
                s[now] = s[n - now - 1] = c;
                now ++;
            }
            // 如果是奇數個，會放到字串的正中間
            if(cnt[i] & 1){
                s[n / 2] = c;
            }
        }
        return s;
    }
};
