#include <bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define pb push_back
 
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

struct dsu{
    int p[100005];
    void init(int n) {iota(p, p+n+1, 0);}
    int find(int u) {return p[u] = (p[u] == u ? u : find(p[u]));}
    int merge(int u, int v){
        u = find(u); v = find(v);
        if(u == v) return 0;
        p[v] = u; return 1;
    }
}dsu;
 
int main(){fastio
    int t; cin >> t;
 
    while(t--){
        int n, m; cin >> n >> m;
        dsu.init(n);
        int ans = 0;
        for(int i=0 ; i<m ; i++){
            int x, y; cin >> x >> y;
            if(x != y){
                ans++;
                if(!dsu.merge(x,y)) ans++;
            }
        }cout << ans << '\n';
    }
    return 0;
}
