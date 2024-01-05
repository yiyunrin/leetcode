# Complexity
- Time complexity: O(nlogn)
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: O(n)
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
### C++
```cpp []
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), cnt = 0;
        vector<int> LIS(n);
        for(int i = 0;i < n;i ++){
            int idx = BS(LIS, nums[i], cnt);
            LIS[idx] = nums[i];
            if(idx >= cnt)
                cnt ++;
        }
        return cnt;
    }
private:
    int BS(vector<int> &LIS, int num, int cnt){
        int l = 0, r = cnt - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(LIS[mid] < num)
                l = mid + 1;
            else if(LIS[mid] >= num)
                r = mid - 1;
        }
        return l;
    }
};
```
### python
```python []
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        cnt = 0
        LIS = [0 for _ in range(n)]
        for num in nums:
            idx = self.BS(LIS, num, cnt)
            LIS[idx] = num
            if idx >= cnt:
                cnt += 1
        return cnt
    
    def BS(self, nums: List[int], num: int, cnt: int) -> int:
        l, r = 0, cnt - 1
        while l <= r:
            mid = l + floor((r - l) / 2)
            if nums[mid] < num:
                l = mid + 1
            elif nums[mid] >= num:
                r = mid - 1
        return l
```
