class Solution {
    func minSwaps(_ s: String) -> Int {
        var n : Int = s.count, r : Int = n - 1, cnt : Int = 0, ans : Int = 0
        var arr = Array(s)
        for i in 0..<n{
            if i > r{
                break
            }
            else if arr[i] == "["{
                cnt += 1
            }
            else if cnt > 0{
                cnt -= 1
            }
            else{
                while arr[r] == "]"{
                    r -= 1
                }
                cnt += 1
                ans += 1
            }
        }
        return ans
    }
}
