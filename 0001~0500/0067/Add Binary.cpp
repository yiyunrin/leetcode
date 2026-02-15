class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size() < b.size())
            swap(a, b);
        b = string(a.size() - b.size(), '0') + b;
        int c = 0;
        for(int i = a.size() - 1;i >= 0;i --){
            int sum = a[i] - '0' + b[i] - '0' + c;
            if(sum & 1)
                a[i] = '1';
            else
                a[i] = '0';
            if(sum > 1)
                c = 1;
            else
                c = 0;
        }
        if(c)
            a = '1' + a;
        return a;
    }
};
