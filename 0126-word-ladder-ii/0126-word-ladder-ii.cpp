class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) return {};  // No transformation possible

        unordered_map<string, vector<string>> parents;  // Track parent nodes for backtracking
        unordered_map<string, int> levels;  // Track BFS levels
        queue<string> q;
        q.push(beginWord);
        levels[beginWord] = 0;

        vector<vector<string>> result;
        int shortestLevel = INT_MAX;

        while (!q.empty()) {
            int qSize = q.size();
            unordered_set<string> visited;  // Track words visited in this level

            for (int i = 0; i < qSize; i++) {
                string word = q.front();
                q.pop();
                int step = levels[word];

                if (step > shortestLevel) continue;  // Stop processing deeper levels

                string originalWord = word;  // Store original word before modification

                for (int j = 0; j < word.size(); j++) {
                    char originalChar = word[j];

                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        word[j] = ch;
                        if (wordSet.find(word) != wordSet.end()) {
                            if (levels.find(word) == levels.end()) {  
                                // New word found, set its level
                                levels[word] = step + 1;
                                q.push(word);
                            }

                            // Store only shortest paths
                            if (levels[word] == step + 1) {
                                parents[word].push_back(originalWord);
                            }

                            if (word == endWord) {
                                shortestLevel = step + 1;  // Mark shortest path level
                            }
                        }
                    }
                    word[j] = originalChar;
                }
            }

            for (const string& w : visited) {
                wordSet.erase(w);  // Remove processed words
            }
        }

        if (parents.find(endWord) == parents.end()) return {};  // No path found

        // Backtrack to construct all valid paths
        vector<string> path = {endWord};
        backtrack(endWord, beginWord, parents, path, result);
        return result;
    }

private:
    void backtrack(string word, string& beginWord, unordered_map<string, vector<string>>& parents, 
                   vector<string>& path, vector<vector<string>>& result) {
        if (word == beginWord) {
            result.push_back(vector<string>(path.rbegin(), path.rend()));  // Reverse path
            return;
        }

        for (const string& parent : parents[word]) {
            path.push_back(parent);
            backtrack(parent, beginWord, parents, path, result);
            path.pop_back();
        }
    }
};
