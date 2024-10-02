class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int, int>> num(n);
        for(int i = 0;i < n;i ++)
            num[i] = {arr[i], i};
        sort(num.begin(), num.end());
        vector<int> ans(n);
        int rank = 0;
        for(int i = 0;i < n;i ++){
            if(i == 0 || num[i].first != num[i - 1].first)
                ++ rank;
            ans[num[i].second] = rank;
        }
        return ans;
    }
};
