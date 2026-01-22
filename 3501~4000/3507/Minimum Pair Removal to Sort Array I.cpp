class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int cnt = 0;
        while(!isNondec(nums)){
            int idx = 0, mn = nums[0] + nums[1];
            for(int i = 0;i < nums.size() - 1;i ++){
                if(nums[i] + nums[i + 1] < mn){
                    mn = nums[i] + nums[i + 1];
                    idx = i;
                }
            }
            nums.erase(nums.begin() + idx);
            nums[idx] = mn;
            cnt ++;
        }
        return cnt;
    }
private:
    bool isNondec(vector<int> &nums){
        for(int i = 0;i < nums.size() - 1;i ++)
            if(nums[i] > nums[i + 1])
                return false;
        return true;
    }
};
