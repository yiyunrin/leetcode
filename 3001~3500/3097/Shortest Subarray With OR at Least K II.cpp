class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        if(k == 0)
            return 1;
        int l = 0, r = 0, n = nums.size(), sum = 0, ans = n + 1;
        vector<int> bits(30, 0);
        while(r < n){
            while(r < n && sum < k){
                add(nums[r], bits, sum);
                r ++;
            }
            while(l <= r && sum >= k){
                ans = min(ans, r - l);
                sub(nums[l], bits, sum);
                l ++;
            }
        }
        if(ans == n + 1)
            return -1;
        return ans;
    }
private:
    void add(int num, vector<int> &bits, int &sum){
        int cnt = 0;
        while(num){
            if(num & 1){
                if(bits[cnt] == 0)
                    sum += (1 << cnt);
                bits[cnt] ++;
            }
            cnt ++;
            num = (num >> 1);
        }
    }
    void sub(int num, vector<int> &bits, int &sum){
        int cnt = 0;
        while(num){
            if(num & 1){
                bits[cnt] --;
                if(bits[cnt] == 0)
                    sum -= (1 << cnt);
            }
            cnt ++;
            num = (num >> 1);
        }
    }
};
