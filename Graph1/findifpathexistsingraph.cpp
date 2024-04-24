class Solution {
public:
    class Graph{
      public :
      unordered_map<int,list<int>> adjlist;

      void addedge(int u,int v){
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
      }

    void check(int src,unordered_map<int,bool> &visited){
        queue<int> q;
        q.push(src);
        visited[src]=true;
        while(!q.empty()){
            int fnode=q.front();
            q.pop();

            for(auto neighbour :adjlist[fnode]){
                if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour]=true;
                }
            }
        }
    } 
    };

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
     Graph g;
     unordered_map<int,bool> visited;
     
     for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        g.addedge(u,v);
     } 
        g.check(source,visited);
         if(!visited[destination]){
            return false;
         }
    return true;
    }
};
