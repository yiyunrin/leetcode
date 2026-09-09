class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        int sum1 = source[0] + source[1], sum2 = target[0] + target[1];
        // 判斷是否在同一個顏色上(都在黑/白)
        // 黑：偶數，白：奇數
        if(sum1 % 2 != sum2 % 2)
            return -1;
        // 如果垂直和水平距離相同
        // 只需一次
        if(abs(source[0] - target[0]) == abs(source[1] - target[1]))
            return 1;
        // 否則需要兩次
        return 2;
    }
};
