#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, q, k;
vector<ll> a, t;

void update(int nd, int s, int e, int idx, int xx)
{
    if(s>idx || idx>e) return;
    t[nd] += xx;
    if(s!=e){
        int m = (s+e)/2;
        update(nd*2, s, m, idx, xx);
        update(nd*2+1, m+1, e, idx, xx);
    }
}

ll query(int nd, int s, int e, int l, int r)
{
    if(l>e || r<s) return 0;
    if(l<=s && e<=r) return t[nd];
    int m = (s+e)/2;
    return query(nd*2, s, m, l, r) + query(nd*2+1, m+1, e, l, r);
}

int main()
{ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> q;
    a.resize(n); t.resize(4*n);
    for(int i=0 ; i<q ; i++){
        cin >> k;
        if(k==1){
            int pp, xx;
            cin >> pp >> xx;
            update(1, 0, n-1, pp-1, xx);
        }
        else{
            int pp, qq;
            cin >> pp >> qq;
            cout << query(1, 0, n-1, pp-1, qq-1) << "\n";
        }
    }
    return 0;
}
