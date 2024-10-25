class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> ans;
        int len;
        string pre;
        for(int i = 0;i < folder.size();i ++){
            if(i == 0 || (folder[i].substr(0, len) != pre || (folder[i].size() > len && folder[i][len] != '/'))){
                ans.push_back(folder[i]);
                pre = folder[i];
                len = pre.size();
            }
        }
        return ans;
    }
};
