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

vl s;

struct DSU {
    ll n; vi pa;
    DSU(ll _n):n(_n) { pa.resize(n+1); iota(all(pa), 0); }
    ll find(ll a) { return a == pa[a] ? a : (pa[a] = find(pa[a])); }
    void merge(ll a, ll b) { 
        ll A = find(a), B = find(b);
        if(s[A] <= s[B]) pa[B] = pa[A];
        else pa[A] = pa[B];
    }
    ll check(ll a, ll b) { return find(a) == find(b); }
};

int main(){fastio
    ll n, m, k; cin >> n >> m >> k; s = vl(n+1);
    DSU dsu(n); vl c(n+1); iota(++c.begin(), c.end(), 2); c[n] = 1;
    for(int i=1 ; i<=n ; ++i) cin >> s[i];
    for(int i=0 ; i<m ; ++i) {
        ll a, b; cin >> a >> b;
        if(a == n) { c[a] = -1; continue; }
        if(a > b) swap(a, b);
        c[a] = -1;
    }
    for(int i=1 ; i<=n ; ++i) if(c[i] != -1) dsu.merge(i, c[i]);
    map<ll, ll> mp;
    for(int i=1 ; i<=n ; ++i) {
        ll k = dsu.find(i);
        mp[k] = s[k];
    }
    ll res = 0;
    for(auto it : mp) res += it.second;
    if(res <= k || m <= 1) cout << "YES";
    else cout << "NO\n";

    return 0;
}