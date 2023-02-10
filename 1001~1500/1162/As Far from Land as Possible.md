<style>
    /* 頁面整體設定 */
    html, body, .ui-content {
    background: #2C2C2C;
    color: #00FFD5;
}
    /* tag顏色設定 */
.markdown-body h6 {
    font-size: .85em;
    color: #A5FFE5;
    -webkit-animation: discolor 5s linear infinite,
                      glint 2s ease infinite;
          animation: discolor 5s linear infinite,
                      glint 2s ease infinite;
    /*animation: discolor 5s linear infinite,
               glint 2s ease infinite;*/
}   
    /* 設定右上角留言按鈕 */
#comment-app .open-comments {
    background: transparent;
}
.btn-default {
  background: transparent;
  border-color: #A5FFE599;
    -webkit-animation: discolor 5s linear infinite,
                      glint 2s ease infinite;
          animation: discolor 5s linear infinite,
                      glint 2s ease infinite;
}
.btn-default:hover {
  background: transparent;
}
.ui-comment-app .open-comments .btn.ui-open-comments {
  color: #A5FFE599;
}
.ui-comment-app .open-comments .btn.ui-open-comments:hover {
  color: #A5FFE5;
}
    /* 設置愛心、收藏、小鈴鐺按鈕 */
.community-button {
  color: #A5FFE580;
    -webkit-animation: discolor 5s linear infinite,
                      glint 2s ease infinite;
          animation: discolor 5s linear infinite,
                      glint 2s ease infinite;
}
.community-button:hover {
  color: #A5FFE5;
  background: transparent;
}
    /* 設定 code 模板 */
    .markdown-body code,
.markdown-body tt {
    background-color: #ffffff36;
}
.markdown-body .highlight pre,
.markdown-body pre {
    color: #ddd;
    background-color: #00000080;
}
.hljs-tag {
    color: #ddd;
}
.token.operator {
  background-color: transparent;
}
    /* h1, h2 樣式 */
.markdown-body h1,
.markdown-body h2 {
    border-bottom-color: #ffffff80;
    text-shadow: 3px 3px 3px #009B67;
}

    /* 設定小目錄的背景顏色 */
.ui-toc-dropdown {
    background-color: #2C2C2C;
}
    /* 設定行動裝置中，小目錄按鈕 */
.ui-toc-label.btn {
    background: linear-gradient(180deg, #2BE8CF60 0%, #2B83E860 100%);
    color: #ffffff90;
}
.ui-toc-label.btn:hover {
    background: linear-gradient(180deg, #2BE8CF90 0%, #2B83E890 100%);
    color: #ffffff;
}
    /* 設定小目錄內連結 */
.ui-toc-dropdown .nav>li>a,
.toc-menu>a {
    color: #D4F9FF;
    font-weight: bold;
}
.ui-toc-dropdown .nav>li>a:focus,
.ui-toc-dropdown .nav>li>a:hover {
    color: #00FFD5;
    border-left: 1px solid #00FFD5;
}

.ui-toc-dropdown .nav>.active:focus>a,
.ui-toc-dropdown .nav>.active:hover>a,
.ui-toc-dropdown .nav>.active>a {
    color: #00FFD5;
    border-left: 1px solid #00FFD5;
/*     -webkit-animation: discolor 5s linear infinite,
                        glint 2s ease infinite;
            animation: discolor 5s linear infinite,
                        glint 2s ease infinite; */
}

.toc-menu>a:focus,
.toc-menu>a:hover {
    color: #00FFD5;
}
    /* 回到最上面的按鈕 */
.markdown-body a > .fa-chevron-up {
    position: fixed;
    bottom: 20px;
    right: 20px;
    padding: 4px;
    border-radius: 4px;
    color: #fff;
    background: linear-gradient(180deg, #2BE8CF60 0%, #2B83E860 100%);
}
.markdown-body a:hover > .fa {
    background: linear-gradient(180deg, #2BE8CF95 0%, #2B83E895 100%);
    -webkit-animation: discolor 5s linear infinite,
                        glint 2s ease infinite;
            animation: discolor 5s linear infinite,
                        glint 2s ease infinite;
}
    /* 右邊滾動軸 */
::-webkit-scrollbar {
    width: 10px;
}
::-webkit-scrollbar-track {
    background: transparent;
}
::-webkit-scrollbar-thumb {
    background: linear-gradient(180deg, #2BE8CF60 0%, #2B83E860 100%);
    border-radius: 3px;
}
::-webkit-scrollbar-thumb:hover {
    background: linear-gradient(180deg, #2BE8CF95 0%, #2B83E895 100%);
}
    /* 設定連結 */
a,
.open-files-container li.selected a {
    color: #89FFF8;
    
}
a:hover,
.open-files-container li.selected a:hover {
    color: #89FFF8;
}
    /* 上面的名字顏色修改 */
.text-gray-900 {
    --tw-text-opacity: 1;
    color: #95FFFF;
    animation: discolor 5s linear infinite,
               glint 2s ease infinite;
}

/* 下面的名字顏色修改 */
/* 這個會修改到最下面的HackMD 但不會閃爍*/   
.footer a {
    color: #95FFFF;
}
.text-black-brand {
    --tw-text-opacity: 1;
    animation: discolor 5s linear infinite,
               glint 2s ease infinite;
}
/* 動畫 */
@keyframes discolor {
    0%, 100% {filter: hue-rotate(0);}
    50% {filter: hue-rotate(180deg);}
}
</style>

###### tags: `LeetCode`
# 1162. As Far from Land as Possible

## 題目
0是水，1是陸地。
找一格離最近的陸地距離最長的水，並回傳距離。


<a href = "https://leetcode.com/problems/as-far-from-land-as-possible/description/"><i class="	fa fa-bug"></i> 題目連結</a>

## 程式碼

```cpp=
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) 
    {
        int ans = 0, count = 0, n = grid.size();
        //count：計算現在grid中有幾個1
        queue<pair<int, int>> step;    //存是1的座標
        for(int i = 0;i < n;++ i)    //找原本grid裡的1
            for(int j = 0;j < n;++ j)
                if(grid[i][j] == 1)
                {
                    step.push({i, j});
                    ++ count;
                }

        while(!step.empty() && count != n * n)
        //如果全部都是1就結束
        {
            int tmp = step.size();    
            //算現在這個距離要做幾次
            ++ ans;
            for(int i = 0;i < tmp;i ++)
            {
                auto [x, y] = step.front();
                step.pop();
                for(int j = max(0, x - 1);j <= min(x + 1, n - 1);++ j)    //上下左右
                    for(int k = max(0, y - 1);k <= min(y + 1, n - 1);++ k)
                        if((j == x || k == y) && !grid[j][k])
                        {
                            step.push({j, k});
                            grid[j][k] = 1;
                            ++ count;
                        }
            }
        } 
        return ans == 0 ? -1 : ans;
    }
};
```
## DATE

2023/02/10
