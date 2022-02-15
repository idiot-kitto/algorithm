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

int d[1010][1010], check[1010];
vpii v(1);

int main(){fastio
    for(int i=0 ; i<1010 ; ++i) for(int j=0 ; j<1010; ++j) d[i][j] = 1e9;

    int n, t; cin >> n >> t;
    for(int i=1 ; i<=n ; ++i) {
        int s, x, y; cin >> s >> x >> y;
        if(s) check[i] = 1;
        v.pb({x, y});
    }

    for(int i=1 ; i<=n ; ++i) {
        int fx = v[i].first, fy = v[i].second;
        for(int j=1; j<=n ; ++j) {
            if(i == j) continue;
            int tx = v[j].first, ty = v[j].second;
            d[i][j] = abs(fx - tx) + abs(fy - ty);
        }
    }

    for(int k=1 ; k<=n ; ++k) 
        for(int i=1 ; i<=n ; ++i) 
            for(int j=1 ; j<=n ; ++j) {
                if(check[i] && check[j]) d[i][j] = min(d[i][j], t);
                else d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }

    int m; cin >> m;
    while(m--) {
        int a, b; cin >> a >> b;
        cout << d[a][b] << '\n';
    }
    return 0;
}