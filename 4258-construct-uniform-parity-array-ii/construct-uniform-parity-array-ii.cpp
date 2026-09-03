class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int mnOdd = INT_MAX;

        for (int x : nums)
            if (x & 1)
                mnOdd = min(mnOdd, x);

        if (mnOdd == INT_MAX)
            return true;

        for (int x : nums)
            if (!(x & 1) && x < mnOdd)
                return false;

        return true;
    }
};