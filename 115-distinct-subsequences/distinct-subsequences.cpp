class Solution {
public:
    // long long  solve(string& s , string& t, int i, int j , vector<vector<long long >>& dp){
    //     if(j<0) return 1;
    //     if(i<0) return 0;
    //     if(dp[i][j]!=-1){
    //         return dp[i][j];
    //     }
    //     if(s[i]==t[j]){
    //         return dp[i][j]=solve(s,t,i-1,j-1,dp)+solve(s,t,i-1,j,dp);
    //     }
    //     return dp[i][j]=solve(s,t,i-1,j,dp);
    // }
    int numDistinct(string s, string t) {
       // vector<vector<long long >> dp(s.length(),vector<long long >(t.length(),-1));
        // vector<vector<long long >> dp(s.length()+1,vector<long long >(t.length()+1,0));
        vector<long double > prev(t.length()+1,0) , curr(t.length()+1,0);
        // for(int i = 0 ;i<=s.length();i++){
        //     dp[i][0]=1;
        // }
        prev[0]=1;
        curr[0]=1;
        // for(int i=1;i<=s.length();i++){
        //     for(int j=1;j<=t.length();j++){
        //         if(s[i-1]==t[j-1]){
        //             curr[j]=prev[j-1]+prev[j];
        //         }
        //         else{
        //             curr[j]=prev[j];
        //         }
        //     }
        //     prev=curr;
        // }
        for(int i=1;i<=s.length();i++){
            for(int j=t.length();j>=1;j--){
                if(s[i-1]==t[j-1]){
                    prev[j]=prev[j]+prev[j-1];
                }
            }
        }
        return prev[t.length()];
        //return solve(s,t,s.length()-1,t.length()-1,dp);
    }
};