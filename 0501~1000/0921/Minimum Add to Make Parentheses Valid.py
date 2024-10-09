class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        cnt = 0; ans = 0
        for ch in s:
            if ch == '(':
                cnt += 1
            elif cnt == 0:
                ans += 1
            else:
                cnt -= 1
        return ans + cnt
        
