class Solution {
public:
    int maxScore(string s) {
        int zero = 0, n = s.size(), ans = 0, one = n;
        for(int i = 0;i < n;i ++)
            if(s[i] == '0')
                one --;
        for(int i = 0;i < n - 1;i ++){
            if(s[i] == '1')
                one --;
            else
                zero ++;

            ans = max(ans, one + zero);
        }
        return ans;
    }
};
