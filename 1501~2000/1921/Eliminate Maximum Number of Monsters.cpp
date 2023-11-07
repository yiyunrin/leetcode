class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = dist.size();
        for(int i = 0;i < n;i ++)
            pq.push(ceil((float)dist[i] / speed[i]));
        int now = 0;
        while(!pq.empty()){
            if(pq.top() <= now){
                return now;
            }
            pq.pop();
            now ++;
        }
        return now;
    }
};
