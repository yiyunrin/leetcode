/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        idx = 0, total = 0;    //初始
        dfs(nestedList);    //dfs
    }
    
    int next() {
        return list[idx ++];
    }
    
    bool hasNext() {
        return idx < total;
    }

private:
    vector<int> list;
    int idx, total;    //idx : 目前的index，total : list總共有多少數字
    void dfs(vector<NestedInteger> &nL){
        int sz = nL.size();
        for(int i = 0;i < sz;i ++){
            if(nL[i].isInteger()){    //如果是數字，放進list
                list.push_back(nL[i].getInteger());
                total ++;
            }
            else    //否則取出vector繼續dfs
                dfs(nL[i].getList());
        }
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
