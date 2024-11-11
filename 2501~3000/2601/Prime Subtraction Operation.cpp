class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        vector<int> prime;
        for(int i = 2;i <= 1009;i ++){
            bool flag = true;
            for(int j = 2;j * j <= i;j ++)
                if(i % j == 0)
                    flag = false;
            if(flag)
                prime.push_back(i);
        }

        for(int i = nums.size() - 2;i >= 0;i --){
            if(nums[i] < nums[i + 1])
                continue;
            int sub = *upper_bound(prime.begin(), prime.end(), nums[i] - nums[i + 1]);
            if(sub >= nums[i])
                return false;
            nums[i] -= sub;
        }
        return true;
    }
};
