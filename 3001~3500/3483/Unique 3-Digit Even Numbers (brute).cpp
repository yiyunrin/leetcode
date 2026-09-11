class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_set<int> num;
        int n = digits.size();
        for(int i = 0;i < n;i ++){
            if(digits[i] == 0)
                continue;
            for(int j = 0;j < n;j ++){
                if(i == j)
                    continue;
                for(int k = 0;k < n;k ++){
                    if(j == k || k == i || (digits[k] & 1))
                        continue;
                    num.insert(digits[i] * 100 + digits[j] * 10 + digits[k]);

                }
            }
        }
        return num.size();
    }
};
