class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int> temp;
        int maxi = INT_MIN;

        for(int i=0; i<nums.size(); i++){
            maxi = max(maxi, nums[i]);
            int ans = gcd(nums[i], maxi);
            temp.push_back(ans);
        }

        sort(temp.begin(), temp.end());
        long long sum = 0;
        for(int i=0; i<temp.size()/2; i++){
            sum += gcd(temp[i],temp[temp.size()-1-i]);
        }
        return sum;
    }
};