class Solution:
    def minSwaps(self, s: str) -> int:
        n = len(s); r = n - 1; cnt = 0; ans = 0
        for i in range(n):
            if i > r:
                break
            elif s[i] == '[':
                cnt += 1
            elif cnt > 0:
                cnt -= 1
            else:
                while s[r] == ']':
                    r -= 1
                ans += 1
                cnt += 1
        return ans
