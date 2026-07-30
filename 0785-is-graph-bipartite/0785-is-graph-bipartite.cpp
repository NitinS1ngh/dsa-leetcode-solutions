class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colour(graph.size(), -1);
        queue<int> q; 

        for(int i=0; i<graph.size(); i++){
            if(colour[i] == -1){
                colour[i] = 0;
                q.push(i);

                while(!q.empty()){
                    int node = q.front();
                    q.pop();

                    for(auto &neighbour: graph[node]){
                        if(colour[neighbour] == -1){
                            colour[neighbour] = (colour[node]+1)%2;
                            q.push(neighbour);
                        }
                        else{
                            if(colour[neighbour] == colour[node]) return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};