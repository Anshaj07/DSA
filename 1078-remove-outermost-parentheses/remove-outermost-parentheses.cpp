class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int l =0;
        int r = 0;
        for(int i =0;i<s.length();i++){
            if(s[i]=='('){
                l++;
            }
            else{
                r++;
            }
            if(l==r){
                l=0;
                r=0;
                continue;
            }
            if(l==1){
                continue;
            }
            
            ans.push_back(s[i]);
        }
        return ans;
    }
};