class Solution {
public:
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) return false;
        }
        return true;
    }

    int maxPalindromes(string s, int k) {
        int n = s.size();
        int cnt = 0;

        for (int i = 0; i <= n - k; i++) {

            if (isPalindrome(s, i, i + k - 1)) {
                cnt++;
                i += k - 1;
            }

            else if (i + k < n && isPalindrome(s, i, i + k)) {
                cnt++;
                i += k;
            }
        }

        return cnt;
    }
};