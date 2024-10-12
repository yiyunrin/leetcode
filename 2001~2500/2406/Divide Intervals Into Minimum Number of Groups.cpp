class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        priority_queue<int, vector<int>, greater<int>> group;
        for(int i = 0;i < n;i ++){
            if(!group.empty() && group.top() < intervals[i][0])
                group.pop();
            group.push(intervals[i][1]);
        }
        return group.size();
    }
};
