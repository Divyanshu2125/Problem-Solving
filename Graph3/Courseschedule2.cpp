class Solution {
public:
    void topoSort(int n,vector<int> &topo,unordered_map<int,list<int>> &adjList){
        queue<int> q;
        map<int,int> indegree;
        for(auto i:adjList){
            for(auto nbr : i.second){
                indegree[nbr]++;
            }
        }
        for(int node=0;node<n;node++){
            if(indegree[node]==0){
                q.push(node);
            }
        }
        while(!q.empty()){
            int fnode=q.front();
            q.pop();
            topo.push_back(fnode);
            for(auto nbr : adjList[fnode]){
                indegree[nbr]--;
                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         unordered_map<int,list<int>> adjList;
        for(auto i:prerequisites){
            int u=i[0];
            int v=i[1];
            adjList[u].push_back(v);
        }
        vector<int> topo;
        topoSort(numCourses,topo,adjList);
        reverse(topo.begin(),topo.end());
        if(topo.size()==numCourses){
            return topo;
        }
        else{
            return {};
        }

    }
};
