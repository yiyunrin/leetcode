class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int r = intervals[0][1], ans = 0, n = intervals.size();
        for(int i = 1;i < n;i ++){
            if(intervals[i][0] < r){
                r = min(r, intervals[i][1]);
                ans ++;
            }
            else
                r = intervals[i][1];
        }
        return ans;
    }
};
