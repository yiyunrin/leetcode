class Solution {
    func minAddToMakeValid(_ s: String) -> Int {
        var arr = Array(s), cnt : Int = 0, ans : Int = 0
        for ch in s{
            if ch == "("{
                cnt += 1
            }
            else if cnt == 0{
                ans += 1
            }
            else{
                cnt -= 1
            }
        }
        return ans + cnt
    }
}
