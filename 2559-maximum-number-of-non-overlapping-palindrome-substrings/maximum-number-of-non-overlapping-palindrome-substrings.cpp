class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        vector<vector<bool>> isPal(n, vector<bool>(n, false));

        // Palindrome preprocessing
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i <= 2 || isPal[i + 1][j - 1])) {
                    isPal[i][j] = true;
                }
            }
        }

        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            dp[i] = dp[i + 1]; // skip

            // take
            for (int j = i + k - 1; j < n; j++) {
                if (isPal[i][j]) {
                    dp[i] = max(dp[i], 1 + dp[j + 1]);
                    break; // first valid palindrome is enough
                }
            }
        }

        return dp[0];
    }
};