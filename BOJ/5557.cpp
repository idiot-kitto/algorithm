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

int main(){fastio
    int n; cin >> n; vi v(n+1); vvl dp(101, vl(21, 0));
    for(int i=1 ; i<=n ; ++i) cin >> v[i];
    dp[1][v[1]] = 1;
    for(int i=2 ; i<n ; ++i) {
        for(int j=0 ; j<=20 ; ++j) {
            if(j + v[i] <= 20) dp[i][j] += dp[i-1][j + v[i]];
            if(j - v[i] >= 0 ) dp[i][j] += dp[i-1][j - v[i]];
        }
    } cout << dp[n-1][v[n]];

    return 0;
}