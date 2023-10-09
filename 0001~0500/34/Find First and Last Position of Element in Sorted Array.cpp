class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, n = nums.size(), r = n - 1;
        vector<int> ans(2, -1);
        //用二分搜找第一個target
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(nums[mid] >= target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        //如果有找到
        if(l < n && nums[l] == target){
            ans[0] = l;
            r = n - 1;
            //用二分搜找最後一個target
            while(l <= r){
                int mid = l + (r - l) / 2;
                if(nums[mid] > target)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            ans[1] = r;
        }
        return ans;
    }
};
