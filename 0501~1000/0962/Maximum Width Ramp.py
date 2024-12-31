class Solution:
    def maxWidthRamp(self, nums: List[int]) -> int:
        stack = []
        n = len(nums)
        sz = 0
        for i in range(n):
            if sz == 0 or nums[stack[sz - 1]] > nums[i]:
                stack.append(i)
                sz += 1
        
        ans = 0
        for i in range(n - 1, 0, -1):
            while sz > 0 and nums[stack[sz - 1]] <= nums[i]:
                ans = max(ans, i - stack[sz - 1])
                stack.pop()
                sz -= 1
        return ans
