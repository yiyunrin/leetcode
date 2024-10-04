class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int n = skill.size(), team = skill[0] + skill[n - 1];
        long long ans = 0;
        for(int i = 0;i < n / 2;i ++){
            if(skill[i] + skill[n - i - 1] != team)
                return -1;
            ans += skill[i] * skill[n - i - 1];
        }
        return ans;
    }
};
