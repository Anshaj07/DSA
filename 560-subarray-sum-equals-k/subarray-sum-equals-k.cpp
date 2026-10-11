class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp ; 
        mp[0] = 1; //sum is 0. at 1 time before starting
        int ans  = 0;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int target = sum - k ;

            if(mp.find(target)!=mp.end()){
                ans+= mp[target];
            }
            mp[sum]++;
        }
        return ans;
    }
};