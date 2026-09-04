class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        
        vector<int> mini(nums.size());
        int m = nums[nums.size()-1];
        mini[nums.size()-1]=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<m){
                m= nums[i];
            }
            mini[i] = m;
        }
        int maxi = nums[0];
        for(int i=0;i<nums.size();i++){
            maxi = max(maxi,nums[i]);
            int a = maxi-mini[i];
            if(a<=k){
                return i;
            }

        }
        return -1;
    }
};