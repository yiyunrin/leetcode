// using sliding window
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int l = 0, r = 0, cnt = 0, n = s.size();
        string ans = "";
        while(l < n){
            if(cnt < k){
                if(r >= n)
                    break;
                if(s[r] == '1')
                    cnt ++;
                r ++;
            }
            else{
                if(s[l] == '1')
                    cnt --;
                l ++;
            }
            if(cnt == k){
                string sub = s.substr(l, r - l);
                if(ans == "" || sub.size() < ans.size() || (sub.size() == ans.size() && sub < ans)){
                    ans = sub;
                }
            }
        }
        return ans;
    }
};
