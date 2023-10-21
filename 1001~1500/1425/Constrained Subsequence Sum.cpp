class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size(), mx = nums[0];
        //second : index, first : 在第index個最大值
        priority_queue<pair<int, int>> pq;
        for(int i = 0;i < n;i ++){
            //找nums裡的最大值
            mx = max(nums[i], mx);
            //把沒有在i-k~i個的去掉
            while(!pq.empty() && pq.top().second < i - k)
                pq.pop();
            //找到第i個的最大值
            if(!pq.empty() && pq.top().first > 0)
                nums[i] += pq.top().first;
            pq.push({nums[i], i});
        }
        return max(mx, pq.top().first);
    }
};
