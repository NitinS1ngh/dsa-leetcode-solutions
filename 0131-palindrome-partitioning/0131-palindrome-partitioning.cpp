class Solution {
public: 
    vector<vector<string>> res;
    bool ispalidrome(string s, int start, int end){
        while(start<end){
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }
    void solve(int idx, vector<string>& ans, string s){
        if(s.size() == idx){
            res.push_back(ans);
            return;
        }

        for(int i=idx; i<s.size(); i++){
            if(ispalidrome(s,idx,i)){
                ans.push_back(s.substr(idx, i-idx+1));
                solve(i+1,ans,s);
                ans.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> ans;
        solve(0,ans,s);
        return res;
    }
};