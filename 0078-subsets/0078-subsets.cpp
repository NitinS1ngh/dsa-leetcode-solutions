class Solution {
public:
    vector<vector<int>> result;
    void solve(int i, vector<int> ans, vector<int>& nums){
        result.push_back(ans);

        for(int start=i; start<nums.size(); start++){
            ans.push_back(nums[start]);
            solve(start+1,ans,nums);
            ans.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ans;
        solve(0,ans,nums);
        return result;
    }
};