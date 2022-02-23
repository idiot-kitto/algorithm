#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back

typedef unsigned long long ll;
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
    ll n; cin >> n;
    ll tmp = n, idx = 0; vl v;
    while(tmp) {
        if(!(tmp&1LL)) v.pb(idx);
        tmp >>= 1LL, idx++;
    }
    ll res = 0LL;
    for(ll k : v) res |= 1LL<<k;
    if(res == 0LL) cout << 1 << '\n' << n;
    else cout << 2 << '\n' << res << '\n' << n;
    
    return 0;
}