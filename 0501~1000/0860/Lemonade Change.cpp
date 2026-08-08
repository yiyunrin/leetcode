class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        // 直接實作每種case的找零方式
        vector<int> cnt(11, 0);
        for(int i = 0;i < bills.size();i ++){
            if(bills[i] == 5){
                cnt[5] ++;
            }
            else if(bills[i] == 10){
                if(cnt[5] <= 0)
                    return false;
                cnt[5] --;
                cnt[10] ++;
            }
            else{
                if(cnt[5] <= 0)
                    return false;
                else if(cnt[10] > 0){
                    cnt[10] --;
                    cnt[5] --;
                }
                else if(cnt[5] < 3){
                    return false;
                }
                else{
                    cnt[5] -= 3;
                }
            }
        }
        return true;
    }
};
