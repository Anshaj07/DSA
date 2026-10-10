class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,
                               int k1, int k2) {
        map<int, long long> mp;
        long long k = 1LL * k1 + k2;
        long long total = 0;

        for (int i = 0; i < nums1.size(); i++) {
            int d = abs(nums1[i] - nums2[i]);
            mp[d]++;
            total += d;
        }

        if (k >= total) return 0;

        while (k > 0) {
            auto it = prev(mp.end());

            int d = it->first;
            long long cnt = it->second;

            if (d == 0) break;

            mp.erase(it);

            int nextD = 0;

            if (!mp.empty()) {
                auto nextIt = prev(mp.end());
                nextD = nextIt->first;
            }

            long long cost = 1LL * (d - nextD) * cnt;

            if (k >= cost) {
                k -= cost;
                mp[nextD] += cnt;
            } else {
                long long q = k / cnt;
                long long r = k % cnt;

                mp[d - q] += cnt - r;

                if (r > 0) {
                    mp[d - q - 1] += r;
                }

                k = 0;
            }
        }

        long long ans = 0;

        for (auto [d, cnt] : mp) {
            ans += 1LL * d * d * cnt;
        }

        return ans;
    }
};