class Solution {
public:
    int countCommas(int n) {
        int digits= 0 ;
        int num=n;
        while(num){
            num=num/10;
            digits++;
        }
        if(digits>3){
            return n-1000+1;
        }
        return 0;
    }
};