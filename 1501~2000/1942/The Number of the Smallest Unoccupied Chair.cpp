class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        vector<int> fri = times[targetFriend];  //存targetFriend
        sort(times.begin(), times.end());  //按照抵達順序排列
        int n = times.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> occu;  //目前有人坐的椅子編號
        priority_queue<int, vector<int>, greater<int>> chair;  //沒人坐的椅子編號
        for(int i = 0;i < n;i ++){
            chair.push(i);
            // 把空了的椅子放回chair裡
            while(!occu.empty() && occu.top().first <= times[i][0]){
                chair.push(occu.top().second);
                occu.pop();
            }
            if(fri == times[i])
                break;
            occu.push({times[i][1], chair.top()});
            chair.pop();
        }
        return chair.top();
    }
};
