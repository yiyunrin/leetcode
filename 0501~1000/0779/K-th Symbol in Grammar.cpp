class Solution {
public:
    int kthGrammar(int n, int k) {
        //如果是第一層，回傳0
        if(n == 1)
            return 0;
        //第n層的第k個 會跟 第n-1層的第(k+1)/2個有關
        int pre = kthGrammar(n - 1, (k + 1) / 2);
        //0 -> 01, 1 -> 10
        //所以如果k是奇數，則回傳pre
        if(k & 1)
            return pre;
        //偶數則0回傳1，1回傳0
        return pre == 0 ? 1 : 0;
    }
};
