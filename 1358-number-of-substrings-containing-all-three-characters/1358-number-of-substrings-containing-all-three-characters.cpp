class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> a(3,0);
        int left = 0;
        int right = 0;
        int ans  = 0;

        while(right<n){
            a[s[right]-'a']++;
            while(left<right && a[0] && a[1] && a[2]){
                ans += n-right;
                a[s[left]-'a']--;
                left++;
            }
            right++;
        }
        return ans;
    }
};