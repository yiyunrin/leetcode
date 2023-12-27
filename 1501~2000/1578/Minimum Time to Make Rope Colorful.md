# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
保留連續同顏色的氣球中neededTime最久的，其餘的刪除。
# Approach
<!-- Describe your approach to solving the problem. -->

### 變數
- ans : 需花費的總時間
- n : 氣球總數
- _max : 連續同顏色的氣球中neededTime的最大值
- sum : 連續同顏色的氣球neededTime的總和

### 方法
- 遍歷所有氣球一次
- 若目前氣球顏色跟前一個相同
    - 更新_max和sum
- 若氣球顏色跟前一個不同
    - 更新ans : sum - _max 就是移除氣球要花費的最短時間
    - 初始_max和sum

# Complexity
- Time complexity: O(n)
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: O(1)
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0, n = colors.size(), _max = neededTime[0], sum = _max;
        for(int i = 1;i < n;i ++){
            if(colors[i] == colors[i - 1]){
                _max = max(_max, neededTime[i]);    //找neededTime的最大值
                sum += neededTime[i];   //計算總時間
            }
            else{
                ans += sum - _max;
                sum = _max = neededTime[i];
            }
        }
        ans += sum - _max;
        return ans;
    }
};
```
