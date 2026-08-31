class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        map<int,vector<int>> adj;
        vector<int> result;
        vector<int> indegree(numCourses,0);
        for(auto it:prerequisites){
            int u = it[0];
            int v = it[1];
            adj[v].push_back(u);
            indegree[u]++;
        }

        queue<int>q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0) q.push(i);
        }

        while(!q.empty()){
            int node=  q.front();
            q.pop();
            result.push_back(node);

            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }

        }

        if(result.size()!=numCourses){
            return {};
        }
        return result;
    }
};