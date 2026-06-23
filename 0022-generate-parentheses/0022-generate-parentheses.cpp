class Solution {
public:
    vector<string> result;
    void solve(int left, int right, string ans){
        if((left==0) && (right==0)){
            result.push_back(ans);
            return;
        }
        if(left<right){
            if(right>0) solve(left,right-1,ans+')');
            if(left>0) solve(left-1,right,ans+'(');
        } 
        if(left == right){
            if(left>0) solve(left-1,right,ans+'(');
        } 
        return;
    }
    vector<string> generateParenthesis(int n) {
        solve(n,n,"");
        return result;
    }
};