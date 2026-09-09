class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;

        long long start = 1000;
        int commas = 1;

        while (start <= n) {
            long long end = min(n, start * 1000 - 1);

            ans += (end - start + 1) * 1LL * commas;

            start *= 1000;
            commas++;
        }

        return ans;
    }
};