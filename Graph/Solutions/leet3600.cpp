class DSU{
    public:
        vector<int>parent,size;
        DSU(int n){
            parent.resize(n+1);
            iota(begin(parent),end(parent),0);
            size.resize(n+1,1);
        }
        int find(int u){
            if(u==parent[u])return u;
            return parent[u] = find(parent[u]);
        }
        void Union(int u,int v){
            int pu = find(u);
            int pv = find(v);
            if(pu==pv)return;
            if(size[pu]>size[pv]){
                parent[pv] = pu;
                size[pu]+=size[pv];
            }
            else{
                parent[pu]=pv;
                size[pv]+=size[pu];
            }
        }
};
class Solution {
public:
    bool check(int mid,int n,vector<vector<int>>& edges,int k){
        DSU dsu(n);
        vector<vector<int>>upgradeCandidate;
        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            int s = edge[2];
            int m = edge[3];

            if(m==1){
                if(s<mid)return false;
                if(dsu.find(u)!=dsu.find(v)){
                    dsu.Union(u,v);
                }
            }
            else {
                if(s>=mid){
                    dsu.Union(u,v);
                }
                else if(2*s>=mid){
                    upgradeCandidate.push_back({u,v});
                }
            }
        }
        for(auto & edge : upgradeCandidate){
            if(dsu.find(edge[0])!=dsu.find(edge[1])){
                if(k<=0)return false;
                dsu.Union(edge[0],edge[1]);
                k-=1;
            }
        }
        int root = dsu.find(0);
        for(int node = 1;node<n;node++){
            if(dsu.find(node)!=root)return false;
        }
        return true;
    }
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        DSU dsu(n);
        for(auto&edge : edges){
            int u = edge[0];
            int v = edge[1];
            int s = edge[2];
            int m = edge[3];
            if(m==1){
                if(dsu.find(u)==dsu.find(v)){
                    return -1;
                }
                dsu.Union(u,v);
            }
        }
        int lo = 1,hi = 200000;
        int result =-1;
        while(lo<=hi){
            int mid = lo+((hi-lo)>>1);
            if(check(mid,n,edges,k)){
                result = mid;
                lo=mid+1;
            }
            else{
                hi = mid-1;
            }
        }
        return result;
    }
};
