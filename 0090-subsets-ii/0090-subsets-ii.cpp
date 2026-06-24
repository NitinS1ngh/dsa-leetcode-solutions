class Solution {
public:
    vector<vector<int>> result;
    void solve(int idx, vector<int> ans, vector<int>& nums){
        result.push_back(ans);

        for(int i=idx; i<nums.size(); i++){
            if(i>idx && nums[i] == nums[i-1]) continue;
            ans.push_back(nums[i]);
            solve(i+1,ans,nums);
            ans.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        solve(0,ans,nums);
        return result;
    }
};