class Solution {
public:
    string largestGoodInteger(string num) {
        int cnt = 1, good = -1;
        for(int i = 1;i < num.size();i ++){
            if(num[i] == num[i - 1])
                cnt ++;
            else
                cnt = 1;
            if(cnt == 3 && (good == -1 || num[i] > num[good]))
                good = i;
        }
        string ans = "";
        if(good != -1)
            for(int i = 0;i < 3;i ++)
                ans += num[good];
        return ans;
    }
};
