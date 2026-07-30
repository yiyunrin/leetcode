class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // 從想要最少的小孩開始分配
        // 從最小的餅乾開始分配
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int j = 0;
        for(int i = 0;i < s.size() && j < g.size();i ++)
            if(g[j] <= s[i])
                j ++;
        return j;
    }
};
