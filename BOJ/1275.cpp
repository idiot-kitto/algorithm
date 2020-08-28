#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, q, x, y, a;
ll b, diff;
vector<ll> arr, tree;

ll init(int node, int s, int e)
{
    int m = (s+e) / 2;
    if(s==e) return tree[node] = arr[s];
    return tree[node] = init(node*2, s, m) + init(node*2+1, m+1, e);
}

void update(int node, int s, int e, int index, ll k)
{
    if(s>index || index>e) return;
    tree[node] += k;
    if(s!=e){
        int m = (s+e) / 2;
        update(node*2, s, m, index, k);
        update(node*2+1, m+1, e, index, k);
    }
}

ll query(int node, int s, int e, int l, int r)
{
    if(l>e || r<s) return 0;
    if(l<=s && e<=r) return tree[node];
    int m = (s+e) / 2;
    return query(node*2, s, m, l, r) + query(node*2+1, m+1, e, l, r);
}

int main()
{ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> q;
    arr.resize(n); tree.resize(n*4);
    for(int i=0 ; i<n ; i++) cin >> arr[i];
    init(1, 0, n-1);
    while(q--){
        cin >> x >> y >> a >> b;
        if(x>y) swap(x,y);
        cout << query(1, 0, n-1, x-1, y-1) << "\n";
        diff = b - arr[a-1];
        arr[a-1] = b;
        update(1, 0, n-1, a-1, diff);
    }
    return 0;
}
