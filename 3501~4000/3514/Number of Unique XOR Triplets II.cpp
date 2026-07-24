class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> pair, ans;
        for(int i = nums.size() - 1;i >= 0;i --){
            for(int j = i;j < nums.size();j ++){
                pair.insert(nums[i] ^ nums[j]);
            }
            for(int tmp: pair){
                ans.insert(nums[i] ^ tmp);
            }
        }
        return ans.size();
    }
};
