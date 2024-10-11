class Solution:
    def smallestChair(self, times: List[List[int]], targetFriend: int) -> int:
        n = len(times)
        tarFri = times[targetFriend]
        times.sort()
        chair = []; occu = []
        for i in range(n):
            heappush(chair, i)
            while len(occu) > 0 and occu[0][0] <= times[i][0]:
                unoccu = heappop(occu)
                heappush(chair, unoccu[1])
            if times[i] == tarFri:
                break
            sit = heappop(chair)
            heappush(occu, [times[i][1], sit])
        return chair[0]
