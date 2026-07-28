class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // {heights, left index}，left index表示這個height最左邊到哪個index
        stack<pair<int, int>> st; // st內容為由小到大的 monotonic stack
        int n = heights.size(), ans = 0;
        for(int i = 0;i < n;i ++){
            ans = max(ans, heights[i]); // 用目前遍歷到的height更新ans
            // right_idx用來在pop時維護ans
            int left_idx = i, right_idx = i - 1;
            while(!st.empty() && st.top().first >= heights[i]){
                pair<int, int> now = st.top();
                st.pop();
                // 從i到now最大面積
                ans = max(ans, heights[i] * (i - now.second + 1));
                // 從i - 1到now的最大面積
                ans = max(ans, now.first * (right_idx - now.second + 1));
                left_idx = now.second;
            }
            st.push({heights[i], left_idx});
        }
        // 最後要把st所有內容都pop出來，並維護ans
        int right_idx = n - 1;
        while(!st.empty()){
            pair<int, int> now = st.top();
            st.pop();
            ans = max(ans, now.first * (right_idx - now.second + 1));
        }
        return ans;
    }
};
