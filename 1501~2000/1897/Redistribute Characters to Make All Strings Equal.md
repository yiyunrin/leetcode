# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
判斷每種字母是否可以平均分配到每個字串。

# Approach
<!-- Describe your approach to solving the problem. -->
### 變數
- cnt : 存26種字母出現的次數
- n : 字串的數量

### 方法
- 遍歷所有字串來計算字母出現的次數
- 判斷是否26種字母的數量都可以被n整除

# Complexity
- Time complexity : O(n * m)
    - m 表示所有字串長度的平均 
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexit y: O(1)
    - 開了一個大小26的陣列 -> 所以是 O(1)
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code

### C++
```cpp
class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int cnt[26] = {0}, n = words.size();
        //計算字母數量
        for(int i = 0;i < n;i ++)
            for(int j = 0;j < words[i].size();j ++)
                cnt[words[i][j] - 'a'] ++;
        //判斷是否能被n整除
        for(int i = 0;i < 26;i ++)
            if(cnt[i] % n != 0)
                return false;
        return true;
    }

};
```
### python
```python
class Solution:
    def makeEqual(self, words: List[str]) -> bool:
        cnt = [0 for _ in range(26)]
        n = len(words)
        # 計算字母數量
        for w in words:
            for c in w:
                cnt[ord(c) - ord('a')] += 1
        # 判斷是否能被n整除
        for i in range(26):
            if cnt[i] % n != 0:
                return False
        return True
```
