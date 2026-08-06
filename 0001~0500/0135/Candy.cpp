class Solution {
public:
    int candy(vector<int>& ratings) {
        int now = 0, n = ratings.size();
        vector<int> tmp(n, 0);
        for(int i = 1;i < n;i ++){
            if(ratings[i] > ratings[i - 1])
                tmp[i] = tmp[i - 1] + 1;
        }
        for(int i = n - 2;i >= 0;i --){
            if(ratings[i] > ratings[i + 1])
                tmp[i] = max(tmp[i], tmp[i + 1] + 1);
        }
        int sum = 0;
        for(int i = 0;i < n;i ++)
            sum += tmp[i];
        return sum + n;
    }
};
