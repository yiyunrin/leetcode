class Solution {
public:
    int maxProduct(int n) {
        int mx1 = 0, mx2 = 0;
        // 遍歷n的每個digits，並儲存最大的兩個digits
        while(n){
            int now = n % 10;
            if(now > mx1){
                mx2 = mx1;
                mx1 = now;
            }
            else if(now > mx2){
                mx2 = now;
            }
            n /= 10;
        }
        return mx1 * mx2;
    }
};
