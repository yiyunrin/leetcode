class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        map<string, string> mp;
        for(int i = 0;i < knowledge.size();i ++){
            mp[knowledge[i][0]] = knowledge[i][1];
        }
        string ans = "", now = "";
        bool l = false;
        for(int i = 0;i < s.size();i ++){
            if(s[i] == '(')
                l = true;
            else if(s[i] == ')'){
                if(mp.find(now) != mp.end())
                    ans += mp[now];
                else
                    ans += '?';
                now = "";
                l = false;
            }
            else if(l)
                now += s[i];
            else
                ans += s[i];
        }
        return ans;
    }
};
