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

int d[303][303];

int main(){fastio
    for(int i=0 ; i<303 ; ++i) for(int j=0 ; j<303 ; ++j) d[i][j] = 1e9;
    int n, m, t; cin >> n >> m >> t;
    for(int i=0 ; i<m ; ++i) {
        int u, v, h; cin >> u >> v >> h;
        d[u][v] = h;
    }

    for(int k=1 ; k<=n ; ++k)
        for(int i=1 ; i<=n ; ++i)
            for(int j=1 ; j<=n ; ++j)
                d[i][j] = min(d[i][j], max(d[i][k], d[k][j]));

    while(t--) {
        int s, e; cin >> s >> e;
        cout << (d[s][e] == 1e9 ? -1 : d[s][e]) << '\n';
    }
    return 0;
}