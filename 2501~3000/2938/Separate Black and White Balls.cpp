class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.size();
        long long ans = 0, white_idx = 0;
        for(int i = 0;i < n;++i){
            if(s[i] == '0'){
                ans += i - white_idx;
                ++white_idx;
            }
        }
        return ans;
    }
};
