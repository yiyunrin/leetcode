class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        //計算travel的prefix sum，並找到G, M, P的最後一個出現在哪
        int ans = 0, m = 0, p = 0, g = 0, n = garbage.size(), pre = 0;
        for(int i = 0;i < n;i ++){
            int sz = garbage[i].size();
            ans += sz;
            for(int j = 0;j < sz;j ++){
                if(garbage[i][j] == 'G')
                    g = pre;
                if(garbage[i][j] == 'M')
                    m = pre;
                if(garbage[i][j] == 'P')
                    p = pre;
            }
            if(i != n - 1)
                pre += travel[i];
        }
        return ans + g + m + p;
    }
};
