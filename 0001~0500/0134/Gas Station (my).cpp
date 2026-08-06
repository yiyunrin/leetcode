class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), mx = -1, from = 0, sum = mx, ans = 0, all = 0;
        // 跑兩圈，找可以讓剩油量最多的起始點
        for(int i = 0;i < 2*n;i ++){
            int now = i % n;
            if(sum < 0){
                from = now;
                sum = 0;
            }
            all += gas[now] - cost[now];
            sum += gas[now] - cost[now];
            if(sum > mx){
                ans = from;
                mx = sum;
            }
        }
        if(all < 0)
            return -1;
        return ans;
    }
};
