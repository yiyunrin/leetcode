class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // 先排序
        // 先按身高排序(小到大)
        // 如果一樣高，按照k排序(大到小)
        sort(people.begin(), people.end(), [](vector<int> a, vector<int> b){
            if(a[0] != b[0])
                return a[0] < b[0];
            return a[1] > b[1];
        });
        int n = people.size();
        vector<bool> space(n, true);
        vector<vector<int>> ans(n, vector<int>());
        // 按照排好的順序，依序放到ans中
        for(int i = 0;i < n;i ++){
            int idx = find(space, people[i][1]);
            space[idx] = false;
            ans[idx] = people[i];
        }
        return ans;
    }
private:
    // 用來計算要放在哪個index
    // 找第k + 1個空位來放
    int find(vector<bool> &space, int n){
        for(int i = 0;i < space.size();i ++){
            if(n < 0)
                return i - 1;
            if(space[i])
                n --;
        }
        return space.size() - 1;
    }
};
