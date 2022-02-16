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

int d[101][101];

int main(){fastio
    int t; cin >> t;
    while(t--) {
        for(int i=0 ; i<101 ; ++i) for(int j=0 ; j<101 ; ++j) d[i][j] = 1e9;
        int n, m; cin >> n >> m;
        for(int i=1 ; i<=m ; ++i) {
            int a, b, c; cin >> a >> b >> c;
            d[a][b] = min(d[a][b], c); d[b][a] = min(d[b][a], c);
        }

        for(int a=1 ; a<=n ; ++a)
            for(int i=1 ; i<=n ; ++i)
                for(int j=1 ; j<=n ; ++j) {
                    if(i == j) d[i][j] = 0;
                    else d[i][j] = min(d[i][j], d[i][a] + d[a][j]);
                }

        int k; cin >> k; vi v(k);
        for(int i=0 ; i<k ; ++i) cin >> v[i];
        int ans = 1e9, idx;
        for(int i=1 ; i<=n ; ++i) {
            int tmp = 0;
            for(auto val : v) tmp += d[val][i];
            if(tmp < ans) idx = i, ans = tmp;
        } cout << idx << '\n';
    }
    return 0;
}