// 暴力解
class Solution {
public:
    int smallestNumber(int n, int t) {
        while(n){
            if(product(n) % t == 0)
                return n;
            n ++;
        }
        return -1;
    }
private:
    int product(int n){
        int re = 1;
        while(n){
            re *= n % 10;
            n /= 10;
        }
        return re;
    }
};
