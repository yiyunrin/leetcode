class Solution {
public:
    int minSwaps(string s) {
        int n = s.size(), r = n - 1, cnt = 0, ans = 0;
        for(int i = 0;i < n;i ++){
            if(s[i] == '[')
                cnt ++;
            else{
                if(cnt > 0)
                    cnt --;
                else{
                    while(s[r] == ']')
                        r --;
                    s[r] = ']';
                    cnt ++;
                    ans ++;
                }
            }
        }
        return ans;
    }
};
