class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> result; //for final result
        vector<int> indegree(V,0); //indegree
        map<int,vector<int>> mpp; //graph
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            mpp[u].push_back(v);
            indegree[v]++;
            
        }
        
        queue<int> q; //queue
        
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            result.push_back(node);
            
            for(auto it:mpp[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        
        if(result.size()!=V){
            return {};
        }
        return result;
        
    }
};