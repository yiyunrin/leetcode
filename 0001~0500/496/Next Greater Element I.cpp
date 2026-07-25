class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        unordered_map<int, int> greater;
        stack<int> st;
        // 找nums2中每個元素的greater
        for(int num: nums2){
            // 符合條件表示num是st.top()的greater
            while(!st.empty() && num > st.top()){
                greater[st.top()] = num; // 把greater存在map中
                st.pop();
            }
            st.push(num);
        }
        // 把剩下沒有greater的都設成-1
        while(!st.empty()){
            greater[st.top()] = -1;
            st.pop();
        }
        vector<int> ans(n1);
        // 用map找nums1的每個元素的greater
        for(int i = 0;i < n1;i ++){
            ans[i] = greater[nums1[i]];
        }
        return ans;
    }
};
