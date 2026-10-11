class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        vector<int> ans(size,0);
        stack<int> st;
        for(int i = size-1;i>=0;i--){
            int ct =temperatures[i];
            while(!st.empty() && temperatures[st.top()]<=ct){
                st.pop();
            }
            if(!st.empty()){
                ans[i]=st.top()-i;
            }
            st.push(i);
        }
        return ans;
    }
};