class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> us;
        while(n != 1){
            if(us.find(n) != us.end())
                return false;
            us.insert(n);
            int tmp = 0;
            while(n){
                int now = n % 10;
                tmp += now * now;
                n /= 10;
            }
            n = tmp;
        }
        return true;
    }
};
