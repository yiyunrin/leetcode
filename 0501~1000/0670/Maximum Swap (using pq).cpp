// using priority queue
class Solution {
public:
    int maximumSwap(int num) {
        vector<int> nums;
        while(num){
            nums.push_back(num % 10);
            num /= 10;
        }
        int n = nums.size();
        vector<int>idx(2, 0);
        priority_queue<pair<int, int>> pq;
        for(int i = 0;i < n;i ++){
            if(!pq.empty() && pq.top().first > nums[i]){
                idx[0] = pq.top().second;
                idx[1] = i;
            }
            if(pq.empty() || nums[i] > pq.top().first)
                pq.push({nums[i], i});
        }
        swap(nums[idx[0]], nums[idx[1]]);
        int ans = 0;
        for(int i = n - 1;i >= 0;i --)
            ans = ans * 10 + nums[i];
        return ans;
    }
};
