class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), ans = 0;
        // {height, index}
        stack<pair<int, int>> st; // st內容為遞減數列
        for(int i = 0;i < n;i ++){
            int pre = height[i];
            while(!st.empty() && height[i] >= st.top().first){
                pair<int, int> now = st.top();
                st.pop();
                // 計算可以裝水的容量
                ans += max(0, (min(now.first, height[i]) - pre)) * (i - now.second - 1);
                pre = now.first; // 紀錄目前計算到哪個高度
            }
            // push進去之前，也要看看跟前一個之間有沒有空間裝水
            if(!st.empty())
                ans += max(0, (min(st.top().first, height[i]) - pre)) * (i - st.top().second - 1);
            st.push({height[i], i});
        }
        return ans;
    }
};
