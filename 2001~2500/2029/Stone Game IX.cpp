// 1 1 2 1 2 1 2 1 
// 2 2 1 2 1 2 1 2 
class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> cnt(3, 0);
        int n = stones.size();
        for(int i = 0;i < n;i ++){
            cnt[stones[i] % 3] ++;
        }
        if(cnt[1] > 0){
            int turns = min(cnt[1] - 1, cnt[2]);
            int have = cnt[1] - 1 - turns > 0 ? 1 : 0;
            int safe = 1 + turns * 2 + have + cnt[0];
            if(safe != n && safe % 2 == 1)
                return true;
        }
        if(cnt[2] > 0){
            int turns = min(cnt[2] - 1, cnt[1]);
            int have = cnt[2] - 1 - turns > 0 ? 1 : 0;
            int safe = 1 + turns * 2 + have + cnt[0];
            if(safe != n && safe % 2 == 1)
                return true;
        }
        return false;
    }
};
