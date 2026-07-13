class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        string s = "123456789";

        int mini = to_string(low).size();
        int maxi = to_string(high).size();

        for(int i=mini; i<=maxi; i++){
            for(int j=0; j+i<=9; j++){
                int temp = stoi(s.substr(j,i));
                if (temp >= low && temp <= high) ans.push_back(temp);
            }
        }

        return ans;
    }
};