class Solution {
public:
    vector<int> result;
    vector<vector<int>> ans;

    void solve(int index, int sum, int target, vector<int>& candidates) {
        if (sum == target) {
            ans.push_back(result);
            return;
        }
        if (index >= candidates.size() || sum > target) return;

        result.push_back(candidates[index]);
        solve(index, sum + candidates[index], target, candidates);
        result.pop_back();

        solve(index + 1, sum, target, candidates);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(0, 0, target, candidates);
        return ans;
    }
};
