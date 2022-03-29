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
    int n; vi pa, sz;
    DSU(int _n):n(_n) { pa.resize(101010); iota(all(pa), 0); sz = vi(101010, 1); }
    int find(int a) { return a == pa[a] ? a : (pa[a] = find(pa[a])); }
    void merge(int a, int b) { 
        int fa = find(a), fb = find(b);
        if(fa != fb) sz[fa] += sz[fb];
        pa[fb] = fa; 
    }
    int check(int a, int b) { return find(a) == find(b); }
};

int main(){fastio
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        DSU dsu(n);
        map<string, int> mp;
        int idx = 1;
        for(int i=0 ; i<n ; ++i) {
            string s, ss; cin >> s >> ss;
            if(!mp[s]) { mp[s] = idx; idx++; }
            if(!mp[ss]) { mp[ss] = idx; idx++; }
            if(dsu.sz[dsu.find(mp[s])] >= dsu.sz[dsu.find(mp[ss])]) dsu.merge(mp[s], mp[ss]);
            else dsu.merge(mp[ss], mp[s]);
            cout << max(dsu.sz[dsu.find(mp[s])], dsu.sz[dsu.find(mp[ss])]) << '\n';
        }
    }
    return 0;
}