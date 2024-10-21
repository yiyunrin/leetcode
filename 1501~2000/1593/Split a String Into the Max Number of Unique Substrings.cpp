class Solution {
public:
    int maxUniqueSplit(string s) {
        ans = 0, n = s.size();
        dfs(0, s);
        return ans;
    }
private:
    int ans, n;
    unordered_set<string> sub;
    void dfs(int now, string &s){
        if(now >= n)
            ans = max(ans, (int)sub.size());
        for(int i = 1;i + now <= n;i ++){
            string tmp = s.substr(now, i);
            if(sub.count(tmp) == 0){
                sub.insert(tmp);
                dfs(now + i, s);
                sub.erase(tmp);
            }
        }
    }
};
