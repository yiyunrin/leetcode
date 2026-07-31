class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        vector<int> letter(26, 0);
        // 先計算每個字母出現的次數
        for(int i = 0;i < n;i ++){
            letter[word[i] - 'a'] ++;
        }
        // 將次數排序
        sort(letter.begin(), letter.end());
        int ans = 0;
        // 由次數多的放到次數少的，讓次數多的排在前面
        for(int i = 25;i >= 0 && letter[i];i --){
            ans += letter[i] * ((25 - i + 8) >> 3);
        }
        return ans;
    }
};
