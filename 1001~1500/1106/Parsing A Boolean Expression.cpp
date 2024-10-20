class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        for(int i = 0;i < expression.size();i ++){
            if(expression[i] == ')'){
                bool t = false, f = true;
                while(1){
                    char c = st.top();
                    st.pop();
                    if(c == 't')
                        t = true;
                    else if(c == 'f')
                        f = false;
                    else if(c == '('){
                        bool b;
                        char oper = st.top();
                        st.pop();
                        if(oper == '|')
                            b = (t | f);
                        else if(oper == '&')
                            b = (t & f);
                        else if(oper == '!')
                            b = !(t & f);
                        if(b)
                            st.push('t');
                        else
                            st.push('f');
                        break;
                    }
                }
            }
            else if (expression[i] == ',')
                continue;
            else
                st.push(expression[i]);
        }
        if(st.top() == 't')
            return true;
        return false;
    }
};
