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

ll d[303][303][303];

int main(){fastio
    int n, q; cin >> n >> q;
    for(int i=1 ; i<=n ; ++i)
        for(int j=1 ; j<=n ; ++j) {
            cin >> d[i][j][0];
            if(i != j && !d[i][j][0]) d[i][j][0] = 1e18;
        }
    
    for(int k=1 ; k<=n ; ++k) 
        for(int i=1 ; i<=n ; ++i) 
            for(int j=1 ; j<=n ; ++j) 
                d[i][j][k] = min(d[i][j][k-1], d[i][k][k-1] + d[k][j][k-1]);

    while(q--) {
        int C, s, e; cin >> C >> s >> e;
        if(d[s][e][C-1] == 1e18) cout << -1 << '\n';
        else cout << d[s][e][C-1] << '\n';
    }
    
    return 0;
}