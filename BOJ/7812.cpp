#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define SIZE 100001

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

vl v[10101];
ll dp[10101], cnt[10101];
bool check[10101];
map<pll, ll> mp;
ll nn;

void go(ll n) {
    if(check[n]) return;
    check[n] = true;
    cnt[n] = 1;

    for(auto next : v[n]) {
        if(check[next]) continue;
        go(next);
        dp[n] += dp[next] + mp[{n,next}] * cnt[next];
        cnt[n] += cnt[next];
    }
}

void go2(ll n) {
    if(check[n]) return;
    check[n] = true;

    for(auto next : v[n]) {
        if(check[next]) continue;
        dp[next] = dp[n] + mp[{n,next}] * (nn - 2 * cnt[next]);
        go2(next);
    }
}

int main(){fastio
    while(1) {
        cin >> nn; if(!nn) break;
        for(ll i=0 ; i<10101 ; ++i) {
            v[i].clear();
            mp.clear();
            dp[i] = 0;
            check[i] = false;
        }
        for(ll i=0 ; i<nn-1 ; ++i) {
            ll a, b, w; cin >> a >> b >> w;
            v[a].pb(b); v[b].pb(a);
            mp[{a,b}] = w; mp[{b,a}] = w;
        }
        go(0);
        for(ll i=0 ; i<10101 ; ++i) check[i] = false;
        go2(0);
        ll ans = 1e18;
        for(ll i=0 ; i<nn ; ++i) ans = min(ans, dp[i]);
        cout << ans << '\n';
    }
    return 0;
}
