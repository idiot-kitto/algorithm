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
int dir[3][2] = {{-1,0}, {-1,-1}, {-1,1}};

int arr[1010][1010];
ll v[1010][1010];

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
    for(int i=0 ; i<m ; ++i) {
        int a, b; cin >> a >> b;
        dsu.merge(a, b);
    }
    int ans = 0, prev;
    for(int i=0 ; i<n ; ++i) {
        int k; cin >> k;
        if(!i) prev = k;
        else {
            if(!dsu.check(prev, k)) ans++;
            prev = k;
        }
    } cout << ans;
    
    return 0;
}