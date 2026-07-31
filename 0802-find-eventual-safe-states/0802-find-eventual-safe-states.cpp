class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> revgraph(n);
        vector<int> indeg(n,0);
        vector<int> ans;

        for(int i=0; i<n; i++)
        for(int j=0; j<graph[i].size(); j++){

            revgraph[graph[i][j]].push_back(i);
            indeg[i]++;
        }

        queue<int> q;

        for(int i=0; i<n; i++){
            if(indeg[i] == 0) q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto &neighbour: revgraph[node]){
                indeg[neighbour]--;
                if(indeg[neighbour]==0) q.push(neighbour);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};