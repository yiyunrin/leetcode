class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        // 計算全部總分
        for(int i = 0;i < n;i ++)
            sum += nums[i];
        // 計算Player1最多可以拿幾分
        int score = MinMax(nums, 0, n - 1, 1);
        // 如果Player1的分數大於等於Player2的分數，則表示Player1贏
        return score >= sum - score;
    }
private:
    int MinMax(vector<int> &nums, int st, int ed, int layer){
        // 如果沒有數字可以拿了
        if(st > ed)
            return 0;
        // 如果輪到Player1
        // 選Player1可以拿比較多分數的方案
        if(layer == 1){
            int front = nums[st] + MinMax(nums, st + 1, ed, 2),
                tail = nums[ed] + MinMax(nums, st, ed - 1, 2);
            return max(front, tail);
        }
        // 如果輪到Player2
        // 選會讓Player1拿比較少分數的方案(不會把分數加總到score中)
        else{
            int front = MinMax(nums, st + 1, ed, 1),
                tail = MinMax(nums, st, ed - 1, 1);
            return min(front, tail);
        }
    }
};
