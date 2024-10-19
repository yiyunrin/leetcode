class Solution {
public:
    char findKthBit(int n, int k) {
        if(k == 1)
            return '0';
        int half = (1 << (n - 1));
        if(k == half)
            return '1';
        else if(k < half)
            return findKthBit(n - 1, k);
        else
            return '1' - findKthBit(n - 1, half - (k - half)) + '0';
    }
};
