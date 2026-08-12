class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // 先用起始點排序
        sort(points.begin(), points.end());
        int ans = 1, r = points[0][1], n = points.size();
        // 用終點判斷是否有重疊
        // 有重疊表示可以用同一支箭射
        // 沒重疊就需要新的箭
        for(int i = 1;i < n;i ++){
            if(points[i][0] > r){
                ans ++;
                r = points[i][1];
            }
            else{
                r = min(r, points[i][1]);
            }
        }
        return ans;
    }
};
