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

ll dist[801][801];

int main(){fastio
    int n, e; cin >> n >> e;

    for(int i=1 ; i<=n ; i++)
        for(int j=1 ; j<=n ; j++)
            dist[i][j] = (i == j? 0 : INT_MAX);
            
    for(int i=0 ; i<e ; i++){
        int a, b, c; cin >> a >> b >> c;
        dist[a][b] = dist[b][a] = c;
    }
    int n1, n2; cin >> n1 >> n2;
    for(int k=1 ; k<=n ; k++)
        for(int i=1 ; i<=n ; i++)
            for(int j=1 ; j<=n ; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    ll ans;
    ans = min(dist[1][n1] + dist[n1][n2] + dist[n2][n], dist[1][n2] + dist[n2][n1] + dist[n1][n]);
    if(ans > 3*800*1000) cout << -1;
    else cout << ans;

    return 0;
}
