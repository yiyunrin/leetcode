class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size(), i = 0, j = 0;
        vector<int> arr1(n), arr2(n);
        arr1[0] = nums[0];
        arr2[0] = nums[1];
        for(int k = 2;k < n;k ++){
            if(arr1[i] > arr2[j]){
                i ++;
                arr1[i] = nums[k];
            }
            else{
                j ++;
                arr2[j] = nums[k];
            }
        }
        for(int k = 0;k <= i;k ++)
            nums[k] = arr1[k];
        for(int k = 0;k <= j;k ++)
            nums[k + i + 1] = arr2[k];
        return nums;
    }
};
