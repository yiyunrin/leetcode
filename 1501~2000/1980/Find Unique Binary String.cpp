class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size(), now = 0;
        sort(nums.begin(), nums.end());
        sz = nums[0].size();
        for(int i = 0;i < n;i ++){
            if(now < toNum(nums[i]))
                break;
            now ++;
        }
        return toStr(now);
    }
private:
    int sz;
    int toNum(string s){
        int num = 0, n = sz;
        for(int i = 0;i < n;i ++){
            num = num << 1;
            num += s[i] - '0';
        }
        return num;
    }

    string toStr(int num){
        string s = "";
        int cnt = 0;
        while(cnt < sz){
            s = (char)(num % 2 + '0') + s;
            num /= 2;
            cnt ++;
        }
        return s;
    }
};
