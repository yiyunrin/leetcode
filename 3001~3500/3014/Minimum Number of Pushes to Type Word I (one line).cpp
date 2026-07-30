// 醜醜的一行解XD
class Solution {
public:
    int minimumPushes(string word) {
        return (1 + (word.size() >> 3)) * (((word.size() >> 3) << 2) + (word.size() & 7));
    }
};
