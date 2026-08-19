class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        map<int, vector<bool>> group;
        int ans = n * 2;
        // 紀錄哪些blocks不能坐
        for(int i = 0;i < reservedSeats.size();i ++){
            if(group.find(reservedSeats[i][0]) == group.end())
                group[reservedSeats[i][0]] = vector<bool>(3, true);
            reserve(reservedSeats[i][0], reservedSeats[i][1], group);
        }
        // 根據紀錄扣除不能坐的blocks數量
        for(auto g : group){
            ans -= count_seat(g.second);
        }
        return ans;
    }
private:
    // 依據題目區間判斷
    void reserve(int row, int seat, map<int, vector<bool>> &group){
        int re = 0;
        if(seat >= 2 && seat <= 5){
            group[row][0] = false;
        }
        if(seat >= 4 && seat <= 7){
            group[row][1] = false;
        }
        if(seat >= 6 && seat <= 9){
            group[row][2] = false;
        }
    }
    int count_seat(vector<bool> &group){
        if(group[0] && group[2])
            return 0;
        if(group[0] || group[1] || group[2])
            return 1;
        return 2;
    }
};
