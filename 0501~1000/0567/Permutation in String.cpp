class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        if(n1 > n2)
            return false;
        vector<int> cnt1(26, 0), cnt2(26, 0);
        for(int i = 0;i < n1;i ++)
            cnt1[s1[i] - 'a'] ++, cnt2[s2[i] - 'a'] ++;
        for(int i = n1;i < n2;i ++){
            if(cnt1 == cnt2)
                return true;
            cnt2[s2[i - n1] - 'a'] --;
            cnt2[s2[i] - 'a'] ++;
        }
        return cnt1 == cnt2;
    }
};
