# Approach
<!-- Describe your approach to solving the problem. -->
### 變數
- n : nums的大小
- arr : 要回傳的二維振烈
- row : 目前arr的row數量
- cnt : 相同數字的數量

### 方法
1. 先把nums由小到大排序
2. 再把相同的數字分到不同的row
    - 如果row的數量不夠，就多加一個row

# Complexity
- Time complexity: O(n log n)
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: O(n)
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
### C++
```c++ []
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size(), row = 0, cnt = 0;
        sort(nums.begin(), nums.end());
        vector<vector<int>> arr;
        for(int i = 0;i < n;i ++){
            //計算相同數字的數量
            if(i == 0 || nums[i] != nums[i - 1])    
                cnt = 1;
            else
                cnt ++;
            //row不夠多 -> 加一個row
            if(cnt > row){  
                arr.push_back({});
                row ++;
            }
            arr[cnt - 1].push_back(nums[i]);
        }
        return arr;   
    }
};
```
### python
```python []
class Solution:
    def findMatrix(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        row = 0
        cnt = 0
        arr = []
        nums.sort()
        for i in range (n):
            #計算相同數字的數量
            if i == 0 or nums[i] != nums[i - 1]:
                cnt = 1
            else:
                cnt += 1
            #row不夠多 -> 加一個row
            if cnt > row:
                arr.append([])
                row += 1
            arr[cnt - 1].append(nums[i])
        return arr
```
