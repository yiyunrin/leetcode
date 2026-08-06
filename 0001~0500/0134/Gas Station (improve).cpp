class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int current = 0, total = 0, from = 0;
        for(int i = 0;i < gas.size();i ++){
            current += gas[i] - cost[i];
            total += gas[i] - cost[i];
            // 如果剩油量小於0，表示不可能從前面的station開始
            // 設定下一個station為起始點
            if(current < 0){
                current = 0;
                from = i + 1;
            }
        }
        if(total < 0)
            return -1;
        return from;
    }
};
