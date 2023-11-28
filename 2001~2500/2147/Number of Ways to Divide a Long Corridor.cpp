class Solution {
public:
    int numberOfWays(string corridor) {
        int n = corridor.size();
        long long seat = 0, plant = 0, ans = 1;
        for(int i = 0;i < n;i ++){
            if(corridor[i] == 'S'){
                if(seat > 0 && seat % 2 == 0)
                    ans = ans * (plant + 1) % 1000000007;
                seat ++;
                plant = 0;
            }
            else
                plant ++;
        }
        if(seat == 0 || seat % 2 == 1)
            return 0;
        return ans;
    }
};
