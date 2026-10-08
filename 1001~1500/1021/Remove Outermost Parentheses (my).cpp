class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        vector<bool> remove(n, false);
        stack<int> st;
        for(int i = 0;i < n;i ++){
            if(s[i] == '('){
                st.push(i);
            }
            else{
                if(st.size() == 1){
                    remove[i] = true;
                    remove[st.top()] = true;
                }
                st.pop();
            }
        }
        string ans = "";
        for(int i = 0;i < n;i ++){
            if(!remove[i]){
                ans += s[i];
            }
        }
        return ans;
    }
};
