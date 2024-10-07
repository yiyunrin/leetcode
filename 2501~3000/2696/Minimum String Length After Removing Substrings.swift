class Solution {
    func minLength(_ s: String) -> Int {
        var stack = [Character]()
        for ch in s{
            if stack.isEmpty == false && ((stack.last == "A" && ch == "B") || (stack.last == "C" && ch == "D")){
                stack.removeLast()
            }
            else{
                stack.append(ch)
            }
        }
        return stack.count
    }
}
