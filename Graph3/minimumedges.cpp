int minimumEdgeReversal(vector<vector<int>> &edges,int n,int src,int dst)
        {
              vector<pair<int,int>> adj[n+1];
            
            for(int i=0; i<edges.size(); ++i) {
                adj[edges[i][0]].push_back({edges[i][1],0});
                adj[edges[i][1]].push_back({edges[i][0],1});
            }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
             vector<int> dist(n+1,1e9);
            dist[src]=0;
            pq.push({0,src});  
             while(!pq.empty()) {
                auto it=pq.top();
                pq.pop();
                
                int d=it.first, node=it.second;
                
                for(auto i:adj[node]) {
                    if(d+i.second<dist[i.first]) {
                        dist[i.first]=d+i.second;
                        pq.push({d+i.second,i.first});
                    }
                }
            }
            if(dist[dst]==1e9) {
                return -1;
            }
            return dist[dst];
        }
