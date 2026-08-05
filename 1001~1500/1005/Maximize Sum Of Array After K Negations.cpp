class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        // 用pq排序，每次挑最小的來操作
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0;i < nums.size();i ++){
            pq.push(nums[i]);
        }
        while(k --){
            int now = pq.top();
            pq.pop();
            pq.push(now * -1);
        }
        // 加總
        int ans = 0;
        while(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};
