class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> cnt(26, 0);
        n = s.size();
        // counting
        for(int i = 0;i < n;i ++){
            cnt[s[i] - 'a'] ++;
        }
        return dfs(0, false, cnt, "", target);
    }
private:
    int n;
    string dfs(int now, bool gt, vector<int> &cnt, string ans, string &tar){
        // cout << ans << endl;
        if(now >= n){
            if(gt)
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
                re = dfs(now + 1, gt || (i > tar[now] - 'a'), cnt, ans + (char)(i + 'a'), tar);
                if(re != "")
                    break;
                cnt[i] += 1;
            }
        } 
        return re;
    }
};
