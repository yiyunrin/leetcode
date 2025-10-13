class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        string pre = "";
        vector<string> ans;
        for(int i = 0;i < words.size();i ++){
            string s = words[i];
            sort(s.begin(), s.end());
            if(pre != s){
                ans.push_back(words[i]);
                pre = s;
            }
        }
        return ans;
    }
};
