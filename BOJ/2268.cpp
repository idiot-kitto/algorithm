#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, q;
vector<ll> a, tree;

void update(int node, int s, int e, int idx, int v)
{
    if(s>idx || idx>e) return;
    tree[node] += v;
    if(s!=e){
        int m = (s+e)/2;
        update(node*2, s, m, idx, v);
        update(node*2+1, m+1, e, idx, v);
    }
}

ll query(int node, int s, int e, int l, int r)
{
    if(l>e || r<s) return 0;
    if(l<=s && e<=r) return tree[node];
    int m = (s+e)/2;
    return query(node*2, s, m, l, r) + query(node*2+1, m+1, e, l, r);
}

int main()
{ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    a.resize(n); tree.resize(4*n);
    for(int i=0 ; i<m ; i++){
        cin >> q;
        if(q){
            int idx; ll v; cin >> idx >> v;
            ll diff = v - a[idx-1];
            a[idx-1] = v;
            update(1, 0, n-1, idx-1, diff);
        }
        else{
            int l, r; cin >> l >> r;
            if(l>r) swap(l,r);
            cout << query(1, 0, n-1, l-1, r-1) << "\n";
        }
    }
    return 0;
}

/*
★ 35번 줄 ★
이 문장이 없으면 이후 diff를 계산할 때 가장 최근에 변경된 값이 아닌 
항상 처음의 값과의 차이만큼 update를 수행하게 된다.
*/
