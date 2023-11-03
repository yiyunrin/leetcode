class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int now = 1, pop = 0;
        for(int i = 0;i < target.size();i ++){
            while(target[i] != now){
                pop ++;
                ans.push_back("Push");
                now ++;
            }
            if(target[i] == now){
                while(pop){
                    ans.push_back("Pop");
                    pop --;
                }
                ans.push_back("Push");
                now ++;
            }
        }
        return ans;
    }
};
