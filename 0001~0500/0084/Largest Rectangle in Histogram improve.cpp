class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        // {heights, left index}，left index表示這個height最左邊到哪個index
        stack<pair<int, int>> st; // st內容為由小到大的 monotonic stack
        int n = heights.size(), ans = 0;
        for(int i = 0;i < n;i ++){
            ans = max(ans, heights[i]); // 用目前遍歷到的height更新ans
            int left_idx = i;
            while(!st.empty() && st.top().first >= heights[i]){
                pair<int, int> now = st.top();
                st.pop();
                // 從i - 1到now的最大面積
                ans = max(ans, now.first * (i - now.second));
                left_idx = now.second;
            }
            st.push({heights[i], left_idx});
        }
        return ans;
    }
};
