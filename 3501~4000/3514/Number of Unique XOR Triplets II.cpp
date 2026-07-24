// 暴力解會TLE
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> pair, ans;
        for(int i = nums.size() - 1;i >= 0;i --){
            // 紀錄後面的所有pair的解果
            for(int j = i;j < nums.size();j ++){
                pair.insert(nums[i] ^ nums[j]);
            }
            // 直接跟紀錄的pair結果做XOR運算，避免重複的pair運算
            for(int tmp: pair){
                ans.insert(nums[i] ^ tmp);
            }
        }
        // ans的大小即為答案
        return ans.size();
    }
};
