class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int i = 0;i < nums.size();i ++)
            pq.push(nums[i]);
        long long ans = 0;
        while(k --){
            int tmp = pq.top();
            pq.pop();
            ans += tmp;
            pq.push(ceil((double)tmp / 3));
        }
        return ans;
    }
};
