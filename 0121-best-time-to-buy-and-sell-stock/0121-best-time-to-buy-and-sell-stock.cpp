class Solution {
public:
    int maxProfit(vector<int>& nums) {
        
        int mini = nums[0];
        int profit = 0;
        for(int i=1; i<nums.size(); i++){
            mini = min(mini, nums[i]);
            profit = max(profit, nums[i]-mini);
        }

        return profit;
    }
};