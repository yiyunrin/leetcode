# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
當字母出現第二次以上，計算與第一次出現之間有幾個字母。
# Approach
<!-- Describe your approach to solving the problem. -->
### 變數
- n : s的長度
- idx : 紀錄每個字母第一次出現的index，初始為-1

### 方法
- 若這個字母第一次出現(idx[] = -1)，紀錄當前index
- 若這個字母出現第二次以上，計算與第一次出現之間的字母數
# Complexity
- Time complexity: O(n)
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: O(1)
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```cpp
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.size(), ans = -1;
        vector<int> idx (26, -1);
        for(int i = 0;i < n;i ++){
            if(idx[s[i] - 'a'] == -1)
                idx[s[i] - 'a'] = i;
            else
                ans = max(ans, i - idx[s[i] - 'a'] - 1);
        }
        return ans;
    }
};
```
