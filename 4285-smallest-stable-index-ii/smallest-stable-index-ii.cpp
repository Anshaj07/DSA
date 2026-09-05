class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        
        int n =nums.size();

        vector<int> mini(n);
        mini[n-1]=nums[n-1];
        int m=nums[n-1];
        for(int i=n-2;i>=0;i--){
            m=min(nums[i],m);
            mini[i]=m;
        }
        int maxi=nums[0];
        for(int i=0;i<n;i++){
            maxi =max(maxi,nums[i]);
            int score = maxi-mini[i];
            if(score<=k){
                return i;
            }
        }
        return -1;
    }
};