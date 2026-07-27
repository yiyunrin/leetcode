class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> ans(n);
        // 儲存{數值, index}
        stack<pair<int, int>> st;
        for(int i = n - 1;i >= 0;i --){
            int cnt = 0;
            // stack中的數值只會遞減，所以比temp[i]小的值都要pop掉
            while(!st.empty() && st.top().first <= temp[i]){
                cnt += ans[st.top().second]; // 計算要隔幾天溫度才會變高
                st.pop();
            }
            if(st.empty()) // 如果st為空，表示沒有溫度變高的一天
                ans[i] = 0;
            else
                ans[i] = cnt + 1;
            st.push({temp[i], i});
        }
        return ans;
    }
};
