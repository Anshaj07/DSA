class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int size = nums.size();
        vector<int> absnums(size,0);
        for(int i=0;i<size;i++){
            absnums[i] = abs(nums[i]);
        }
        sort(absnums.begin(),absnums.end());
        int count = 0;
        long long ans=0;
        int i = 0;
        int j = size-1;
        bool first = true;
        while(count!=size){
            if(first){
                ans+=absnums[j]*absnums[j];
                j--;
                first = false;

            }
            else{
                ans-=absnums[i]*absnums[i];
                i++;
                first = true;
            }
            count++;
        }
        return ans;
    }
};