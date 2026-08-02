class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for(int i = 1;i < prices.size();i ++){
            // 只要價格比前一天高，獲利就加兩天的價格差
            if(prices[i] > prices[i - 1])
                ans += prices[i] - prices[i - 1];
        }
        return ans;
    }
};
