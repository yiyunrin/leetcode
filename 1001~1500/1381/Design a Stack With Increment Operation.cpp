class CustomStack {
public:
    CustomStack(int maxSize) {
        mx = maxSize;  // maximum number of elements
        ele = 0;  // number of elements in stack
        st = vector<int>(mx);  // stack
    }
    
    void push(int x) {
        if(ele == mx)
            return;
        st[ele] = x;
        ele ++;
    }
    
    int pop() {
        if(ele == 0)
            return -1;
        ele --;
        return st[ele];
    }
    
    void increment(int k, int val) {
        for(int i = 0;i < min(k, ele);i ++)
            st[i] += val;
    }
private:
    int mx, ele;
    vector<int> st;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
