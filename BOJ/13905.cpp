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

struct DSU {
    ll n; vl pa;
    DSU(ll _n):n(_n) { pa.resize(n+1); iota(all(pa), 0); }
    ll find(ll a) { return a == pa[a] ? a : (pa[a] = find(pa[a])); }
    void merge(ll a, ll b) { pa[find(b)] = find(a); }
    ll check(ll a, ll b) { return find(a) == find(b); }
};

int main(){fastio
    ll n, m, s, e; cin >> n >> m >> s >> e;
    ll mn = 1e18, mx = -1;
    vector<tuple<ll, ll, ll>> v;
    while(m--) {
        ll a, b, c; cin >> a >> b >> c;
        mn = min(mn, c), mx = max(mx, c);
        v.eb(a, b, c);
    }

    ll l = mn, r = mx, ans = 0;
    while(l<=r) {
        DSU dsu(n);
        ll m = (l + r) / 2;
        for(auto [a, b, c] : v) if(m <= c) dsu.merge(a, b);
        if(dsu.check(s, e)) ans = max(ans, m), l = m + 1;
        else r = m - 1;
    } cout << ans;

    return 0;
}
