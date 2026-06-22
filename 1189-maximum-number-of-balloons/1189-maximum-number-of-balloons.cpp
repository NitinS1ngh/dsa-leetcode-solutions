class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> mp;
        for(int i=0; i<text.size(); i++){
            if(text[i] == 'b' || text[i] == 'a' || text[i] == 'l' || text[i] == 'o' || text[i] == 'n') mp[text[i]]++;
        } 

        if(mp.size() != 5) return 0;
        int ans = INT_MAX;
        for(auto it: mp){
            if(it.first == 'b' || it.first == 'a' || it.first == 'n'){
                ans = min(ans, it.second);
            }
            if(it.first == 'l' || it.first == 'o'){
                ans = min(ans, it.second/2);
            }
        }        
        return ans == INT_MAX ? 0 : ans;
    }
};