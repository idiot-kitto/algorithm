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

int main(){fastio
    ll n, m; cin >> n >> m; vl prev(1010, 0); vpll v[1010];
    while(m--) {
        ll x, y, z; cin >> x >> y >> z;
        v[x].pb({y, z}); v[y].pb({x, z});
    }

    auto dijkstra = [&](int flag, ll x, ll y) {
        vl w(n+1, 1e18);
        priority_queue<pll, vpll, greater<>> pq;
        pq.push({w[1] = 0, 1});

        while(!pq.empty()) {
            int cw = pq.top().first, cn = pq.top().second; pq.pop();
            if(cw < w[cn]) continue;
            for(auto& k : v[cn]) {
                ll to = k.first, tw = k.second;
                if(!flag && ((x == cn && y == to) || (x == to && y == cn))) continue;

                ll nw = cw + tw;
                if(nw < w[to]) {
                    pq.push({w[to] = nw, to});
                    if(flag) prev[to] = cn;
                }
            }
        } return w[n];
    };

    ll ans = dijkstra(1, 0, 0);
    for(ll i = n ; i > 1 ;) {
        ans = max(ans, dijkstra(0, i, prev[i]));
        i = prev[i];
    } cout << ans;

    return 0;
}