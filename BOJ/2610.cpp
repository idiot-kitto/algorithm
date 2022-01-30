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
    int n; vi pa;
    DSU(int _n):n(_n) { pa.resize(n+1); iota(all(pa), 0); }
    int find(int a) { return a == pa[a] ? a : (pa[a] = find(pa[a])); }
    void merge(int a, int b) { pa[find(b)] = find(a); }
    int check(int a, int b) { return find(a) == find(b); }
};

int arr[101][101];

int main(){fastio
    int n, m; cin >> n >> m;
    for(int i=1 ; i<=n ; ++i) for(int j=1 ; j<=n ; ++j) arr[i][j] = 1e9;
    DSU dsu(n); map<int, vi> mp;
    for(int i=0 ; i<m ; ++i) {
        int a, b; cin >> a >> b;
        dsu.merge(a, b);
        arr[a][b] = 1; arr[b][a] = 1;
    }
    for(int i=1 ; i<=n ; ++i) mp[dsu.find(i)].pb(i);
    
    for(auto it : mp)
        for(auto k : it.second)
            for(auto i : it.second)
                for(auto j : it.second)
                    arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
    
    vi ans;
    for(auto it : mp) {
        int c, mx = 1e9;
        for(auto i : it.second) {
            int tmp = -1;
            for(auto j : it.second) if(i != j) tmp = max(tmp, arr[i][j]);
            if(tmp < mx) mx = tmp, c = i;
        } ans.pb(c);
    } sort(all(ans));
    
    cout << mp.size() << '\n';
    for(auto k : ans) cout << k << '\n';

    return 0;
}