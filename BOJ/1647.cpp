#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define SIZE 100001

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<char> vc;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, int> psi;
typedef pair<int, string> pis;
typedef pair<char, int> pci;
typedef pair<int, char> pic;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
const int mod = 1e9 + 7;
const long double PI = 3.141592653589793238462643383279502884197;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

struct DSU {
    int n; vi pa;
    DSU(int _n):n(_n) { pa.resize(n+1); iota(all(pa), 0); }
    int find(int a) { return a == pa[a] ? a : (pa[a] = find(pa[a])); }
    void merge(int a, int b) { pa[find(b)] = find(a); }
    int check(int a, int b) { return find(a) == find(b); }
};

int main(){fastio
    int n, m; cin >> n >> m;
    DSU dsu(n);
    vector<pair<int,pii>> v;
    for(int i=0 ; i<m ; ++i) {
        int a, b, c; cin >> a >> b >> c;
        v.pb({c,{a,b}});
    } sort(all(v));

    int ans = 0, cnt = 0;
    for(int i=0 ; i<m ; ++i) {
        int cost = v[i].first;
        int x = v[i].second.first, y = v[i].second.second;
        if(dsu.check(x,y)) continue;
        dsu.merge(x,y);
        ans += cost, cnt++;
        if(cnt == n - 1) { ans -= cost; break; }
    } cout << ans;

    return 0;
}
