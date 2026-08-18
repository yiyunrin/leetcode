// using greedy
// 只要第n位大於第n+1位
// 第n位 - 1
// 第n+1位 = 9
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);
        int nine = s.size() + 1;
        for(int i = s.size() - 2;i >= 0;i --){
            if(s[i] > s[i + 1]){
                nine = i + 1;
                s[i] -= 1;
            }
        }
        for(int i = nine;i < s.size();i ++)
            s[i] = '9';
        return stoi(s);
    }
};
