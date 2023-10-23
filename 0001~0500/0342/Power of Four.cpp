class Solution {
public:
    bool isPowerOfFour(int n) {
        long i = 1;
        int cnt = 0, bits = 0;
        while(i <= n){
            if(i & n){
                if(cnt & 1)
                    return false;
                else
                    bits ++;
            }
            i = i << 1;
            cnt ++;
        }
        return bits == 1;
    }
};
