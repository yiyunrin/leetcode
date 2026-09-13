class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> pair1, pair2;
        map<pair<int, int>, int> cnt;
        int ans = 0;
        for(int i = 0;i < n;i ++)
            for(int j = 0;j < n;j ++)
                if(img1[i][j])
                    pair1.push_back({i, j});
        for(int i = 0;i < n;i ++)
            for(int j = 0;j < n;j ++)
                if(img2[i][j])
                    pair2.push_back({i, j});

        for(pair<int, int> i : pair1){
            for(pair<int, int> j : pair2){
                int dx = i.first - j.first,
                    dy = i.second - j.second;
                cnt[{dx, dy}] ++;
                ans = max(ans, cnt[{dx, dy}]);
            }
        }
        return ans;
    }
};
