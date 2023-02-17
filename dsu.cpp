#include <bits/stdc++.h>

using namespace std;
#define int long long

class DSU{
    vector<int> rank, parent, size;
    public:
        DSU(int n){
            rank.resize(n+1, 0);
            parent.resize(n+1);
            size.resize(n+1);
            for(int i=0; i<=n; i++){
                parent[i] = i;
                size[i] = 1;
            }
        }

        int findParent(int node){
            if(parent[node] == node) return node;
            return parent[node] = findParent(parent[node]);
        }

        void union_by_rank(int u, int v){
            int pu = findParent(u);
            int pv = findParent(v);

            if(pu == pv) return;
            if(rank[pu] < rank[pv])
                parent[pu] = pv;
            else if(rank[pv] < rank[pu])
                parent[pv] = pu;
            else{
                parent[pv] = pu;
                rank[pu]++;
            }
        }

        void union_by_size(int u, int v){
            int pu = findParent(u);
            int pv = findParent(v);

            if(pu == pv) return;
            if(size[pu] < size[pv]){
                parent[pu] = pv;
                size[pv] += size[pu];
            }
            else{
                parent[pv] = pu;
                size[pu] += size[pv];
            }
        }
};

signed main(){

ios_base::sync_with_stdio(false);
cin.tie(NULL);

    // cout<<"Hello World\n";

    DSU ds(7);

    ds.union_by_size(1, 2);
    ds.union_by_size(2, 3);
    ds.union_by_size(4, 5);
    ds.union_by_size(6, 7);
    ds.union_by_size(5, 6);

    if(ds.findParent(3) == ds.findParent(7)) cout<<"Same\n";
    else cout<<"Not same\n";

    ds.union_by_size(3, 7);

    if(ds.findParent(3) == ds.findParent(7)) cout<<"Same\n";
    else cout<<"Not same\n";

    return 0;
}