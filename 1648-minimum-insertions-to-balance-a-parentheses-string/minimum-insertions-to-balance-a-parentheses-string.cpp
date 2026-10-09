class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        int need = 0;   // Number of ')' still needed

        for (char ch : s) {
            if (ch == '(') {
                // If we need one ')' to complete a previous pair,
                // insert it before starting a new '('.
                if (need % 2 == 1) {
                    ans++;
                    need--;
                }
                need += 2;
            }
            else { // ch == ')'
                need--;

                // No matching '('
                if (need == -1) {
                    ans++;
                    need = 1;
                }
            }
        }

        return ans + need;
    }
};