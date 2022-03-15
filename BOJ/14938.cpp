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

int val[101], d[101][101];

int main(){fastio
    int n, m, r; cin >> n >> m >> r;
    for(int i=1 ; i<=n ; ++i) cin >> val[i];
    for(int i=1 ; i<=n ; ++i) for(int j=1 ; j<=n ; ++j) d[i][j] = 1e9;
    while(r--) {
        int a, b, l; cin >> a >> b >> l;
        d[a][b] = min(d[a][b], l); d[b][a] = min(d[b][a], l);
    }

    for(int k=1 ; k<=n ; ++k)
        for(int i=1 ; i<=n ; ++i)
            for(int j=1 ; j<=n ; ++j)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    auto go = [&](int start) {
        int tmp = 0;
        for(int i=1 ; i<=n ; ++i) {
            if(i == start) { tmp += val[i]; continue; }
            if(d[start][i] <= m) tmp += val[i];
        } return tmp;
    };

    int ans = -1;
    for(int i=1 ; i<=n ; ++i) ans = max(ans, go(i));
    cout << ans;

    return 0;
}