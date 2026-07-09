class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);  
        
        for (auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]);  
            inDegree[p[0]]++;  // Count incoming edges for each course
        }

        queue<int> q;
        vector<int> order;

        // Add all courses with in-degree 0 (no prerequisites)
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int course = q.front();
            q.pop();
            order.push_back(course);

            for (int neighbor : adj[course]) {
                inDegree[neighbor]--;  
                if (inDegree[neighbor] == 0) {  
                    q.push(neighbor);
                }
            }
        }

        return (order.size() == numCourses) ? order : vector<int>();  
    }
};
