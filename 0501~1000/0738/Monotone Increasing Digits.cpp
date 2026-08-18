class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        if(n < 10)
            return n;
        // build number
        while(n){
            num.push_back(n % 10);
            n /= 10;
        }
        sz = num.size();
        // 從最高位開始dfs
        dfs(sz - 1, 0, true);
        return ans;
    }
private:
    int ans, sz;
    vector<int> num;
    // idx: 目前要判斷的idx
    // now: 目前累積的ans值
    // flag: 用來判斷目前是不是跟n一樣大，如果一樣大，後面的數就不能超過n
    bool dfs(int idx, int now, bool flag){
        // 一有符合的答案就結束dfs
        if(idx < 0){
            ans = now;
            return true;
        }
        // 根據flag判斷可以嘗試的範圍
        int from = now % 10;
        int to = 9;
        if(flag)
            to = num[idx];
        // 從大到小嘗試
        for(int i = to;i >= from;i --){
            bool ok = dfs(idx - 1, now * 10 + i, flag && (i == to));
            if(ok)
                return true;
        }
        return false;
    }
};
