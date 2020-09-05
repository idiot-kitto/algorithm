#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int S=1e5+1;
vector<ll> arr(S),tree(S*4),lazy(S*4);
int n,m,q,a,b;
ll x;
ll init(int nd,int s,int e)
{
    int m=(s+e)/2;
    if(s==e) return tree[nd]=arr[s];
    else return tree[nd]=init(nd*2,s,m)+init(nd*2+1,m+1,e);
}
void update_lazy(int nd,int s,int e)
{
    if(lazy[nd]){
        tree[nd]+=(e-s+1)*lazy[nd];
        if(s!=e){
            lazy[nd*2]+=lazy[nd];
            lazy[nd*2+1]+=lazy[nd];
        }
        lazy[nd]=0;
    }
}
void update_range(int nd,int s,int e,int l,int r,ll d)
{
    update_lazy(nd,s,e);
    if(l>e||r<s) return;
    if(l<=s&&e<=r){
        tree[nd]+=(e-s+1)*d;
        if(s!=e){
            lazy[nd*2]+=d;
            lazy[nd*2+1]+=d;
        }return;
    }
    int m=(s+e)/2;
    update_range(nd*2,s,m,l,r,d);
    update_range(nd*2+1,m+1,e,l,r,d);
    tree[nd]=tree[nd*2]+tree[nd*2+1];
}
ll query(int nd,int s,int e,int l,int r)
{
    update_lazy(nd,s,e);
    if(l>e||r<s) return 0;
    if(l<=s&&e<=r) return tree[nd];
    int m=(s+e)/2;
    return query(nd*2,s,m,l,r)+query(nd*2+1,m+1,e,l,r);
}
int main()
{ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    init(1,1,n);
    cin>>m;
    while(m--){
        cin>>q;
        if(q==1){
            cin>>a>>b>>x;
            update_range(1,1,n,a,b,x);
        }
        else{
            cin>>x;
            cout<<query(1,1,n,x,x)<<"\n";
        }
    }
    return 0;
}
