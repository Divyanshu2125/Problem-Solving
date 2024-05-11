class Solution {
public:
 int networkDelayTime(vector<vector<int>>& times, int n, int k) {
     vector<int> dist(n+1,INT_MAX);
     dist[k]=0;
     
     for(int i=0;i<n-1;i++)
     {
         bool flag=false;
         for(auto node:times)
         {
             int src=node[0];
             int des=node[1];
             int time=node[2];
             if(dist[src]!=INT_MAX&&dist[des]>dist[src]+time)
             {
                 dist[des]=dist[src]+time;
                 flag=true;
             }
         }
         if(flag==false)
             break;
     }
     int res=0;
     for(int i=1;i<=n;i++)
     {
         if(dist[i]==INT_MAX)
             return -1;
         res=max(res,dist[i]);
     }
     return res;
 }
};
