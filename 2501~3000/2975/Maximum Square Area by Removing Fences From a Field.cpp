class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        int mod = 1E9 + 7;

        // 加入第一和最後一條邊，並排序
        hFences.push_back(1);
        hFences.push_back(m);
        sort(hFences.begin(), hFences.end());
        vFences.push_back(1);
        vFences.push_back(n);
        sort(vFences.begin(), vFences.end());

        // 計算所有可能的邊長
        unordered_set<int> h, v;
        for(int i = 0;i < hFences.size();i ++)
            for(int j = i - 1;j >= 0;j --)
                h.insert(hFences[i] - hFences[j]);
        for(int i = 0;i < vFences.size();i ++)
            for(int j = i - 1;j >= 0;j --)
                v.insert(vFences[i] - vFences[j]);
      
        // 找出最長的邊長
        int mx = 0;
        for(int i : h){
            if(v.contains(i)){
                mx = max(mx, i);
            }
        }

        if(mx > 0)
            return 1ll * mx * mx % mod;
        return -1;
    }
};
