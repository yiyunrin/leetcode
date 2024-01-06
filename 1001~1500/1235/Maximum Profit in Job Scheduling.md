# Approach
<!-- Describe your approach to solving the problem. -->
### 變數
- sche : 存每個job的{endTime, startTime, profit}
- dp[i] : 前i - 1個job的最大profit
### 方法
- 把所有jobs用結束時間(endTime)由小到大排序
- 從endTime最小的開始，判斷每個job要不要做
    - dp[i] = max(dp[j] + sche[i][2], dp[i - 1])
    - dp[j]是在現在job的startTime前做完的最大profit

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
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> sche(n + 1);
        for(int i = 0;i < n;i ++){
            sche[i + 1] = {endTime[i], startTime[i], profit[i]};
        }
        sort(sche.begin(), sche.end());
        vector<int> dp(n + 1, 0);
        for(int i = 1;i <= n;i ++){
            int j = BS(sche, sche[i][1], i - 1);
            dp[i] = max(dp[i - 1], sche[i][2] + dp[j]);
        }
        return dp[n];
    }
private:
    int BS(vector<vector<int>> & sche, int num, int n){
        int l = 1, r = n;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(sche[mid][0] <= num)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return r;
    }
};
```
### python
```python []
class Solution:
    def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
        n = len(startTime)
        sche = [[] for _ in range(n + 1)]
        for i in range(n):
            sche[i + 1] = [endTime[i], startTime[i], profit[i]]
        sche.sort()
        dp = [0 for _ in range(n + 1)]
        for i in range(1, n + 1):
            j = self.BS(sche, sche[i][1], i - 1)
            dp[i] = max(dp[i - 1], dp[j] + sche[i][2])
        return dp[n]
    
    def BS(self, sche: List[[int]], num: int, n: int) -> int:
        l, r = 1, n
        while l <= r:
            mid = l + (r - l) // 2
            if sche[mid][0] <= num:
                l = mid + 1
            else:
                r = mid - 1
        return r
    
```
