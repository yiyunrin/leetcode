class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> mod(k, 0);
        for(int i = 0;i < arr.size();i ++){
            int tmp = arr[i] % k;
            if(tmp < 0)
                tmp += k;
            mod[tmp] ++;
        }
        if((mod[0] & 1) != 0)
            return false;
        for(int i = 1;i <= k / 2;i ++){
            if(mod[i] != mod[k - i])
                return false;
        }
        if((k & 1) == 0 && (mod[k / 2] & 1) != 0)
            return false;
        return true;
    }
};
