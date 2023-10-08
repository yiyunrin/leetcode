class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> pro(n1, vector<int>(n2));
        for(int i = 0;i < n1;i ++){
            for(int j = 0;j < n2;j ++){
                pro[i][j] = nums1[i] * nums2[j];    //計算num1[i]和num2[j]的product
                if(j && i)    //比較現在這個 和 現在加上在[i-1][j-1]前的最大值
                    pro[i][j] = max(pro[i][j], pro[i][j] + pro[i - 1][j - 1]);
                if(i)    //比較現在這個 和 左邊一格
                    pro[i][j] = max(pro[i][j], pro[i - 1][j]);
                if(j)    //比較現在這個 和 上面一格
                    pro[i][j] = max(pro[i][j], pro[i][j - 1]);
            }
        }
        //回傳最後一格
        return pro[n1 - 1][n2 - 1];
    }
};
