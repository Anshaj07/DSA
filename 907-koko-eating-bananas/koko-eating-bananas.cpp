class Solution {
public:
    bool isValid(vector<int>& piles,int k, int h){
        long long  hours = 0;
        for(int i=0;i<piles.size();i++){
             if(piles[i]%k==0) hours+=((piles[i])/k);
             else{
                hours+=((piles[i])/k)+1;
             }
        }
        return hours<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int start =1;
        int end = *max_element(piles.begin(),piles.end());
        int ans = 0;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(isValid(piles,mid,h)){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
};