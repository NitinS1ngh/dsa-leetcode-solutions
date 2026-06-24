class Solution {
public:
    vector<string> ans;

    void helper(int idx, string &digits, map<char, string> &mapping, string &curr_str) {
        if (idx == digits.size()) {
            ans.push_back(curr_str);
            return;
        }

        char ch = digits[idx];
        string letters = mapping[ch];
        for (int i = 0; i < letters.size(); i++) {
            curr_str.push_back(letters[i]);
            helper(idx + 1, digits, mapping, curr_str);
            curr_str.pop_back(); // backtracking step
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return ans;

        map<char, string> mapping;
        mapping['2'] = "abc";
        mapping['3'] = "def";
        mapping['4'] = "ghi";
        mapping['5'] = "jkl";
        mapping['6'] = "mno";
        mapping['7'] = "pqrs";
        mapping['8'] = "tuv";
        mapping['9'] = "wxyz";

        string curr_str;
        helper(0, digits, mapping, curr_str);

        return ans;
    }
};
