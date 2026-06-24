class Solution {
public:
    vector<vector<int>> ans;

    void solve(int size, int target, int index, int sum, vector<int> path, int nums[]) {
        if(path.size() == size && sum == target) {
            ans.push_back(path);
            return;
        }

        if(sum > target || index == 9) return; 

        solve(size, target, index+1, sum, path, nums);
        path.push_back(nums[index]);
        solve(size, target, index+1, sum+nums[index], path, nums);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        int nums[9] = {1,2,3,4,5,6,7,8,9};
        vector<int> path;
        solve(k, n, 0, 0, path, nums);
        return ans;
    }
};
