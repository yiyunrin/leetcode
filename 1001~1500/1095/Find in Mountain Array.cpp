1/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        n = mountainArr.length();
        int top = findTop(mountainArr);
        int ans = findTarget1(0, top, target, mountainArr);
        if(ans == -1)
            ans = findTarget2(top, n - 1, target, mountainArr);
        return ans;
    }

private:
    int n;
    int findTop(MountainArray &m){
        int l = 0, r = n - 2;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(m.get(mid) < m.get(mid + 1))
                l = mid + 1;
            else
                r = mid - 1;
        }
        return l;
    }
    int findTarget1(int l, int r, int target, MountainArray &m){
        while(l <= r){
            int mid = l + (r - l) / 2, now = m.get(mid);
            if(now == target)
                return mid;
            else if(now < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;
    }
    int findTarget2(int l, int r, int target, MountainArray &m){
        while(l <= r){
            int mid = l + (r - l) / 2, now = m.get(mid);
            if(now == target)
                return mid;
            else if(now > target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;
    }
};  
