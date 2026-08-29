vector<int> number;
bool my_compare(int a, int b){
    return number[a] < number[b];
}
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> idx(n);
        number = nums;
        for(int i = 0;i < n;i ++)
            idx[i] = i;
        // 根據nums的大小排序index
        sort(idx.begin(), idx.end(), my_compare);
        // 將nums由小到大排序
        sort(number.begin(), number.end());
        // 找出nums差不超過limit的區段
        // 並排序對應的index
        int from = 0;
        for(int i = 1;i < n;i++){
            if(number[i] - number[i - 1] > limit){
                sort(idx.begin() + from, idx.begin() + i);
                from = i;
            }
        }
        sort(idx.begin() + from, idx.end());
        // 把nums填到對應的index中
        vector<int> re(n);
        for(int i = 0;i < n;i ++){
            re[idx[i]] = number[i];
        }
        return re;
    }
};
