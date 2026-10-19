
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tm;

        for (char c : t) {
            tm[c]++;
        }

        int left = 0;
        int start = 0;
        int minLen = INT_MAX;
        int missing = t.size();

        for (int right = 0; right < s.size(); right++) {
            if (tm.find(s[right]) != tm.end()) {
                if (tm[s[right]] > 0) {
                    missing--;
                }
                tm[s[right]]--;
            }

            while (missing == 0) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                if (tm.find(s[left]) != tm.end()) {
                    tm[s[left]]++;

                    if (tm[s[left]] > 0) {
                        missing++;
                    }
                }

                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
