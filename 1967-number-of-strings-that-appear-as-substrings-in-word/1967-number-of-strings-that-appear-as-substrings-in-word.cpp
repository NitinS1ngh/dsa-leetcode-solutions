class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int n = patterns.size();
        int count = 0;
        for(int i=0; i<n; i++){
            int ptr = 0;
            while(ptr<word.size()){
                if(word.substr(ptr,patterns[i].size()) == patterns[i]){
                    count++;
                    break;
                } 
                else ptr++;
            }
        }
        return count;
    }
};