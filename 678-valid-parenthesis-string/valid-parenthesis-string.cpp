class Solution {
public:
    bool checkValidString(string s) {
        stack<int> st;
        stack<int> star;

        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') {
                st.push(i);
            }
            else if(s[i] == ')') {
                if(!st.empty()) {
                    st.pop();
                }
                else if(!star.empty()) {
                    star.pop();
                }
                else {
                    return false;
                }
            }
            else {
                star.push(i);
            }
        }

        while(!st.empty() && !star.empty()) {
            if(st.top() < star.top()) {
                st.pop();
                star.pop();
            }
            else {
                return false;
            }
        }

        return st.empty();
    }
};