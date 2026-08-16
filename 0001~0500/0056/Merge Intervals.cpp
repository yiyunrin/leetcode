class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 用start排序
        sort(intervals.begin(), intervals.end());
        int from = intervals[0][0], end = intervals[0][1];
        vector<vector<int>> ans;
        // 遍歷所有intervals
        // 如果目前的跟前一個interval重疊 -> 合併
        // 否則開新區間
        for(int i = 1;i < intervals.size();i ++){
            if(intervals[i][0] <= end){
                end = max(end, intervals[i][1]);
            }
            else{
                ans.push_back({from, end});
                from = intervals[i][0];
                end = intervals[i][1];
            }
        }
        ans.push_back({from, end});
        return ans;
    }
};
