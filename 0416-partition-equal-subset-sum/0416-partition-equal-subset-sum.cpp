class Solution {
public:
    vector<vector<int>> dp;
    bool solve(int n, int target, vector<int>& nums){

        if(n==0) return (target==nums[0]);
        if(target==0) return true;
        if(dp[n][target]!=-1) return dp[n][target];

        if(nums[n]<=target){
            return dp[n][target] = solve(n-1,target-nums[n],nums) || solve(n-1,target,nums);
        }
        else return dp[n][target] = solve(n-1,target,nums);
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0; 
        for(int i=0; i<n; i++){
            sum = sum+nums[i];
        }
        if(sum%2!=0) return false;
        dp.assign(n,vector<int>((sum/2)+1,-1));
        return solve(n-1,sum/2,nums);
    }
};