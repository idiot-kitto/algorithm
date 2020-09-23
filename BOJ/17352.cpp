#include <bits/stdc++.h>
using namespace std;
int n, a, b;
vector<int> parent;

int find(int u){
    if(u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v){
    u = find(u); v = find(v);
    if(u == v) return;
    parent[u] = v;
}

int main()
{ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n;
    parent.resize(n+1);
    for(int i=1 ; i<=n ; i++) parent[i] = i;
    for(int i=0 ; i<n-2 ; i++){
        cin >> a >> b;
        merge(a,b);
    }
    int k = find(1);
    for(int i=2 ; i<=n ; i++){
        int tmp = find(i);
        if(k != tmp){
            cout << k << " " << tmp;
            break;
        }
    }
    return 0;
}
