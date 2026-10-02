class Solution {
public:
    vector<string> generateParenthesis(int n) {
        dfs(0, 0, n, "");
        return ans;
    }
private:
    vector<string> ans;
    void dfs(int now, int left, int n, string s){
        if(s.size() == n * 2){
            ans.push_back(s);
            return;
        }
        for(int i = left;i < n;i ++){
            string tmp = s + '(';
            dfs(now + i - left + 1, i + 1, n, tmp);
        }
        for(int j = 0;j < now;j ++){
            string tmp = s + ')';
            dfs(now - j - 1, left, n, tmp);
        }
        return;
    }
};
