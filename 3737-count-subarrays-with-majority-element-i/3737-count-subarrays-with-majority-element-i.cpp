class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        //sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            int count = 0;
            for(int j=i; j<nums.size(); j++){
                if(nums[j]==target) count++;
                else count--;
                if(count>0) ans++;
            }
           
        }

        return ans;
    }
}; 