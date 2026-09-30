class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int now = 0, mx_dep = 0;
        int n = seq.size();
        // 先計算 seq 的深度
        for(int i = 0;i < n;i ++){
            if(seq[i] == '('){
                now ++;
                mx_dep = max(mx_dep, now);
            }
            else{
                now --;
            }
        }
        // <= 一半的深度時，就放到 part A
        // > 一半的深度時，就放到 part B
        vector<int> ans(n, 0);
        int half = mx_dep / 2;
        for(int i = 0;i < n;i ++){
            if(seq[i] == '('){
                now ++;
                if(now > half)
                    ans[i] = 1;
            }
            else{
                if(now > half)
                    ans[i] = 1;
                now --;
            }
        }
        return ans;
    }
};
