class Solution {
public:
    int maximumSwap(int num) {
        vector<int> mx(2, 0), pre_mx(2, 0), nums;
        while(num){
            nums.push_back(num % 10);
            num /= 10;
        }
        int n = nums.size();
        for(int i = 0;i < n;i ++){
            if(mx[0] != mx[1])
                pre_mx = mx;
            if(i == 0 || nums[i] > nums[mx[0]])
                mx[0] = mx[1] = i;
            else if(nums[i] < nums[mx[0]])
                mx[1] = i;
        }
        if(mx[0] != mx[1])
            swap(nums[mx[0]], nums[mx[1]]);
        else
            swap(nums[pre_mx[0]], nums[pre_mx[1]]);
        int ans = 0;
        for(int i = n - 1;i >= 0;i --)
            ans = ans * 10 + nums[i];
        return ans;
    }
};
