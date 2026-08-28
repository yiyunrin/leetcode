class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        vector<int> cnt(26, 0);
        n = s.size();
        for(int i = 0;i < n;i ++){
            cnt[s[i] - 'a'] ++;
        }
        int odd = 0;
        for(int i = 0;i < 26;i ++){
            if(cnt[i] & 1){
                s[n / 2] = (char)(i + 'a');
                odd ++;
            }
            cnt[i] /= 2;
        }
        if(odd > 1)
            return "";
        return dfs(0, false, cnt, s, target);
    }
private:
    int n;
    string dfs(int now, bool gt, vector<int> &cnt, string &ans, string &tar){
        if(now >= n / 2){
            if(gt || ans > tar)
                return ans;
            return "";
        }
        string re = "";
        int i = tar[now] - 'a';
        if(gt)
            i = 0;
        for(;i < 26;i ++){
            if(cnt[i] > 0){
                cnt[i] -= 1;
                ans[now] = ans[n - now - 1] = (char)(i + 'a');
                re = dfs(now + 1, gt || (i > tar[now] - 'a'), cnt, ans, tar);
                if(re != "")
                    break;
                cnt[i] += 1;
            }
        } 
        return re;
    }
};
