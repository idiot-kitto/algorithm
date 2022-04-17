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

int dp1[55], dp2[55];

int main(){fastio
    int n; cin >> n;
    dp1[1] = 0, dp2[1] = 1;
    dp1[2] = 1, dp2[2] = 1;
    dp1[3] = 1, dp2[3] = 2;

    for(int i=4 ; i<=45 ; ++i) dp1[i] = dp1[i-2] + dp1[i-1], dp2[i] = dp2[i-2] + dp2[i-1];
    cout << dp1[n] << ' ' << dp2[n];

    return 0;
}