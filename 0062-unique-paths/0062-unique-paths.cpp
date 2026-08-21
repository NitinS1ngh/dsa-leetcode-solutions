class Solution {
public:
    int dp[101][101];
    int solve(int bottom, int right, int m, int n){
        if(right==n-1 || bottom==m-1) return 1;
        if(dp[bottom][right]!=-1) return dp[bottom][right];

        int ans = solve(bottom+1,right,m,n)+solve(bottom,right+1,m,n);
        return  dp[bottom][right] = ans;
    }
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,m,n);
    }
};