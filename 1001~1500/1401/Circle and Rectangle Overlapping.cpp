// 總覺得不太對的寫法XD
class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        for(int i = x1;i <= x2;i ++){
            bool tmp = overlap(radius, xCenter, yCenter, i, y1);
            if(tmp)
                return true;
        }
        for(int i = x1;i <= x2;i ++){
            bool tmp = overlap(radius, xCenter, yCenter, i, y2);
            if(tmp)
                return true;
        }
        for(int i = x1;i <= x2;i ++){
            bool tmp = overlap(radius, xCenter, yCenter, i, (y2 + y1) / 2);
            if(tmp)
                return true;
        }
        for(int i = y1;i <= y2;i ++){
            bool tmp = overlap(radius, xCenter, yCenter, x1, i);
            if(tmp)
                return true;
        }
        for(int i = y1;i <= y2;i ++){
            bool tmp = overlap(radius, xCenter, yCenter, x2, i);
            if(tmp)
                return true;
        }
        for(int i = y1;i <= y2;i ++){
            bool tmp = overlap(radius, xCenter, yCenter, (x2 + x1) / 2, i);
            if(tmp)
                return true;
        }

        return false;
    }
private:
    bool overlap(int r, int xC, int yC, int x, int y){
        long long r2 = r * r;
        long long dis = (x - xC)*(x - xC) + (y - yC)*(y - yC);
        return dis <= r2;
    }
};
