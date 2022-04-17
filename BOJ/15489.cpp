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

int psc[101][101];

int main(){fastio
    for(int i=1 ; i<=100 ; ++i) psc[i][1] = 1, psc[i][i] = 1;
    for(int i=3 ; i<=100 ; ++i) for(int j=2 ; j<i ; ++j) psc[i][j] = psc[i-1][j-1] + psc[i-1][j];
    
    int ans = 0;
    int r, c, w; cin >> r >> c >> w;
    for(int i=r, k=1 ; i<r+w ; ++i, ++k) for(int j=c ; j<c+k ; ++j) ans += psc[i][j];
    cout << ans;    

    return 0;
}
