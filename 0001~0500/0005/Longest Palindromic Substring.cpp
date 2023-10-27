class Solution {
public:
    string longestPalindrome(string s) {
        n = s.size();
        string ans = "";
        for(int i = 0;i < n;i ++){
            //奇數個字母的字串
            string tmp = FindPal(s, i, i);
            if(tmp.size() > ans.size())
                ans = tmp;
            //偶數個字母的字串
            tmp = FindPal(s, i, i + 1);
            if(tmp.size() > ans.size())
                ans = tmp;
        }
        return ans;
    }
private:
    int n;
    //找Palindrome
    string FindPal(string &s, int l, int r){
        string re = "";
        while(l >= 0 && r < n){
            if(s[l] != s[r])
                break;
            l --, r ++;
        }
        l ++;
        re = s.substr(l, r - l);
        return re;
    }
};
