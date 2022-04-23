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
const long double PI = 3.141592653589793238462643383279502884197;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

int lw[202020], re[202020];
ll mod = 1e9 + 7;

ll v[202020];

int main(){fastio
    v[2] = 1; ll d = 4;
    for(ll i=3 ; i<=200000 ; ++i) {
        v[i] = (v[i-1] + (d - 1LL)) % mod;
        d = (d * 2) % mod;
    }

    int n; string s; cin >> n >> s;
    int wcnt = 0;
    for(int i=0 ; i<n ; ++i) {
        if(s[i] == 'W') wcnt++;
        if(s[i] == 'H') lw[i] = wcnt;
    }
    int ecnt = 0;
    for(int i=n-1 ; i>=0 ; --i) {
        if(s[i] == 'E') ecnt++;
        if(s[i] == 'H') re[i] = ecnt;
    }
    
    ll ans = 0;
    for(int i=0 ; i<n ; ++i) 
        if(lw[i] && re[i] >= 2) ans = (ans + lw[i] * v[re[i]]) % mod;
    cout << ans % mod;

    return 0;
}