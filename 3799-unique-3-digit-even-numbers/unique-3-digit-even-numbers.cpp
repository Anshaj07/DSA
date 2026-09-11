class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);
        for (int d : digits)
            freq[d]++;
        int ans = 0;
        for (int num = 100; num <= 998; num += 2) {
            int x = num;
            vector<int> need(10, 0);
            need[x % 10]++;
            x /= 10;
            need[x % 10]++;
            x /= 10;
            need[x % 10]++;
            bool ok = true;
            for (int d = 0; d < 10; d++) {
                if (need[d] > freq[d]) {
                    ok = false;
                    break;
                }
            }
            if (ok) ans++;
        }
        return ans;
    }
};