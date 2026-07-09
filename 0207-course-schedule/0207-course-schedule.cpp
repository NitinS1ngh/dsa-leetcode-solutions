class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (int i = 0; i < prerequisites.size(); i++) {
            int course = prerequisites[i][0];
            int prerequisite = prerequisites[i][1];
            adj[prerequisite].push_back(course);
            indegree[course]++;
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for (int i = 0; i < adj[node].size(); i++) {
                int neighbor = adj[node][i];
                indegree[neighbor]--;

                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return count == numCourses;
    }
};