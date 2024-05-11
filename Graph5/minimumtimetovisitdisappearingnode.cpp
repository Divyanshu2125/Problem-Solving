class Solution {
public:
    void dijekstra(int n,int src,unordered_map<int,list<pair<int,int>>> &adjList,vector<int> &distance,vector<int>& disappear){
        set<pair<int,int>> st;
        st.insert({0,src});
        distance[src]=0;
        while(!st.empty()){
            auto topelement=st.begin();
            pair<int,int> toppair=*topelement;
            int topdist=toppair.first;
            int topnode=toppair.second;
            st.erase(st.begin());
            for(auto nbr : adjList[topnode]){
                int nbrnode=nbr.first;
                int nbrdis=nbr.second;
                if(nbrdis+topdist<distance[nbrnode] && nbrdis+topdist<disappear[nbrnode]){ 
                    auto previous=st.find({distance[nbrnode],nbrnode});
                    if(previous!=st.end()){
                        st.erase(previous);
                    }
                    distance[nbrnode]=nbrdis+topdist;
                    st.insert({distance[nbrnode],nbrnode});
                }
            }
        }
    }
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
     unordered_map<int,list<pair<int,int>>> adjList;
     vector<int> distance(n,INT_MAX);
     for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int w=edges[i][2];
        adjList[u].push_back({v,w});
        adjList[v].push_back({u,w});
     }
       dijekstra(n,0,adjList,distance,disappear);
       for(int i=0;i<distance.size();i++){
        if(distance[i]==INT_MAX){
            distance[i]=-1;
        }
       }
       return distance;
    }
};
