#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
const ll mod = 1e9 + 7;
const long double PI = 3.141592653589793238462643383279502884197;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

ll n, m, a, b, c;
vector<vpll> v(101010);

int main(){fastio
    cin >> n >> m >> a >> b >> c;
    while(m--) {
        ll p, q, w; cin >> p >> q >> w;
        v[p].pb({q, w}); v[q].pb({p, w});
    }

    auto dijkstra = [&](ll cost) {
        vl w(n+1, 1e18);
        priority_queue<pll, vpll, greater<>> pq;
        pq.push({w[a] = 0, a});

        while(!pq.empty()) {
            ll cw = pq.top().first, cn = pq.top().second; pq.pop();
            if(w[cn] < cw) continue;
            for(auto k : v[cn]) {
                ll to = k.first, tw = k.second;
                ll nw = cw + tw;
                if(cost < tw) continue;
                if(nw < w[to] && nw <= c) pq.push({w[to] = nw, to});
            }
        } return w[b];
    };

    ll l = 1, r = c, ans = 1e18;
    while(l <= r) {
        ll m = (l + r) / 2;
        if(dijkstra(m) == 1e18) l = m + 1;
        else ans = min(ans, m), r = m - 1;        
    } cout << (ans == 1e18 ? -1 : ans);

    return 0;
}