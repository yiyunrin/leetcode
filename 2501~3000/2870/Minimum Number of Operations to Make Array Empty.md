# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
先計算每個數字出現的數量，再計算最少的操作次數。
# Approach
<!-- Describe your approach to solving the problem. -->
### 變數
- cnt : 計算每個數字出現的次數

### 方法
- 用unordered_map來計算每個數字出現幾次
- 若有只出現1次的，回傳-1
- 將所有次數/3並無條件進位的總和就是需要操作的最少次數。

# Complexity
n = nums的陣列大小
- Time complexity: O(n)
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: O(n)
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
### C++
```cpp []
class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> cnt;
        //計算次數
        for(int i = 0;i < nums.size();i ++)
            cnt[nums[i]] ++;
        int ans = 0;
        //計算操作次數
        for(auto c : cnt){
            if(c.second == 1)
                return -1;
            //先+2再/3等於無條件進位
            ans += (c.second + 2) / 3;
        }
        return ans;
    }
};
```
### python
```python []
class Solution:
    def minOperations(self, nums: List[int]) -> int:
        cnt = {}
        #計算次數
        for num in nums:
            if cnt.get(num) == None:
                cnt[num] = 1
            else:
                cnt[num] = cnt[num] + 1
        ans = 0
        #計算操作次數
        for val in cnt.values():
            if val == 1:
                return -1
            #無條件進位
            ans += ceil(val / 3)
        return ans
```
