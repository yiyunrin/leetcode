class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        // 先找到所有字母出現的範圍
        vector<pair<int, int>> range(26, {n, -1});
        for(int i = 0;i < n;i ++){
            int now = s[i] - 'a';
            if(range[now].first == n)
                range[now].first = i;
            range[now].second = i;
        }
        // 排序範圍
        sort(range.begin(), range.end());
        int start = 0, r = -1;
        vector<int> ans;
        // 若範圍有重疊，會被切成一組
        for(int i = 0;i < 26;i ++){
            int fir = range[i].first, sec = range[i].second;
            if(fir == n)
                break;
            if(fir > r){
                if(r != -1){
                    ans.push_back(r - start + 1);
                }
                start = fir;
                r = sec;
            }
            else{
                r = max(r, sec);
            }
        }
        ans.push_back(r - start + 1);
        return ans;
    }
};
