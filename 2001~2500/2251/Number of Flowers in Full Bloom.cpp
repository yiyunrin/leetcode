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
