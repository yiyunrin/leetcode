class NumArray {
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        segTree = vector<int> (n << 2, 0);
        cnt = 0;
        build(1, 0, n - 1, nums);
    }
    
    void update(int index, int val) {
        _update(1, index, 0, n - 1, val);
    }
    
    int sumRange(int left, int right) {
        int ans = query(1, 0, n - 1, left, right);
        return ans;
    }
private:
    vector<int> segTree;
    int cnt, n;
    void build(int x, int l, int r, vector<int> &num){
        if(l == r){
            segTree[x] = num[cnt];
            cnt ++;
            return;
        }
        int mid = (l + r) >> 1;
        build(x<<1, l, mid, num);
        build(x<<1|1, mid+1, r, num);
        pull(x);
        return;
    }
    void pull(int x){
        segTree[x] = segTree[x<<1] + segTree[x<<1|1];
        return;
    }
    void _update(int x, int idx, int l, int r, int val){
        if(l == r){
            segTree[x] = val;
            return;
        }
        int mid = (l + r) >> 1;
        if(idx <= mid)
            _update(x<<1, idx, l, mid, val);
        else
            _update(x<<1|1, idx, mid + 1, r, val);
        pull(x);
        return;
    }
    int query(int x, int l, int r, int ql, int qr){
        if(l == r || l == ql && r == qr){
            return segTree[x];
        }
        int mid = (l + r) >> 1;
        int re = 0;
        if(ql <= mid){
            re += query(x<<1, l, mid, ql, min(mid, qr));
        }
        if(qr > mid){
            re += query(x<<1|1, mid + 1, r, max(ql, mid + 1), qr);
        }
        return re;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
