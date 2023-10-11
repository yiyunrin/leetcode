//方法一(自己想的方法)
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        //存花謝的順序
        priority_queue<int, vector<int>, greater<int>> fw;
        //存人到的順序，first：到的時間，second：people的index
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pp;
        for(int i = 0;i < people.size();i ++)
            pp.push({people[i], i});
        //flowers用開花時間排序
        sort(flowers.begin(), flowers.end());
        //now是目前的時間，sum是now的開花數
        int sum = 0, now = 0, i = 0, f_sz = flowers.size();
        while(!pp.empty()){
            //如果now開花
            while(i < f_sz && now == flowers[i][0]){
                sum ++;    //開花數+1
                fw.push(flowers[i][1]);    //存入花謝的時間
                i ++;
            }
            //如果人在now抵達
            while(!pp.empty() && pp.top().first == now){
                people[pp.top().second] = sum;    //存入看到的花數
                pp.pop();
            }
            //如果now花謝
            while(!fw.empty() && fw.top() == now){
                sum --;    //開花數-1
                fw.pop();    
            }
            //找下一個開花數量改變的時間
            int next = INT_MAX;
            if(i < f_sz)
                next = min(next, flowers[i][0]);
            if(!pp.empty())
                next = min(next, pp.top().first);
            if(!fw.empty())
                next = min(next, fw.top());
            now = next;
        }
        return people;
    }
};

//方法二(參考solution)時間較佳
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int fw_sz = flowers.size(), pp_sz = people.size();
        //存花開時間和花謝時間
        vector<int> st(fw_sz), ed(fw_sz);
        for(int i = 0;i < fw_sz;i ++){
            st[i] = flowers[i][0];
            ed[i] = flowers[i][1];
        }
        //由小到大排序
        sort(st.begin(), st.end());
        sort(ed.begin(), ed.end());
        //可以看到的花數是(抵達時間前的開花數)-(抵達時間前的花謝數)
        for(int i = 0;i < pp_sz;i ++)
            people[i] = bs(st, people[i] + 1) - bs(ed, people[i]);
        return people;
    }
private:
    //用binary search在x裡找target的位置
    int bs(vector<int> &x, int target){
        int l = 0, r = x.size() - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(x[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return r;
    }
};
