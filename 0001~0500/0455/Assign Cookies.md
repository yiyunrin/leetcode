# Approach
<!-- Describe your approach to solving the problem. -->
### 變數
- s_sz : s的大小
- g_sz : g的大小
- s_i : s目前的index
- g_i : g目前的index

### 方法
- 先把s和g由小到大排序
- 從最小的g開始找是否有比他大的s

# Complexity
- Time complexity: O(nlogn)
    - n = s的大小 
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: O(1)
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
### C++
```c++ []
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int s_i = 0, ans = 0, g_i = 0, s_sz = s.size(), g_sz = g.size();
        while(s_i < s_sz && g_i < g_sz){
            if(s[s_i] >= g[g_i]){
                ans ++ ;
                g_i ++;
            }
            s_i ++;
        }
        return ans;
    }
};
```
### python
```python []
class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g.sort()
        s.sort()
        g_sz = len(g)
        s_sz = len(s)
        g_i = 0
        s_i = 0
        ans = 0
        while g_i < g_sz and s_i < s_sz:
            if s[s_i] >= g[g_i]:
                ans += 1
                g_i += 1
            s_i += 1
        return ans
```
