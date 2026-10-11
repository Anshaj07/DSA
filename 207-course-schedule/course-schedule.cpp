
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjlist(numCourses);
        stack<int> st;
        vector<int> incomingEdges(numCourses, 0);

        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];

            adjlist[u].push_back(v);
            incomingEdges[v]++;
        }

        for (int i = 0; i < numCourses; i++) {
            if (incomingEdges[i] == 0) {
                st.push(i);
            }
        }

        int count = 0;

        while (!st.empty()) {
            int top = st.top();
            st.pop();
            count++;

            for (auto it : adjlist[top]) {
                incomingEdges[it]--;

                if (incomingEdges[it] == 0) {
                    st.push(it);
                }
            }
        }

        return count == numCourses;
    }
};
