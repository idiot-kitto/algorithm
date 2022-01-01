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

int main(){fastio
    ll n, g, k; cin >> n >> g >> k;
    vl S(n+1, 0), L(n+1, 0), O(n+1, 0);
    for(int i=1 ; i<=n ; ++i) {
        cin >> S[i] >> L[i] >> O[i];
    }

    ll l = 0LL, r = 2e9;
    ll ans = -1;

    while(l <= r) {
        ll m = (l + r) / 2;
        ll res = 0LL;
        vl v;
        for(int i=1 ; i<=n ; ++i) {
            if(O[i]) v.pb(S[i] * max(1LL, m - L[i]));
            else res += (S[i] * max(1LL, m - L[i]));
        } sort(all(v));
        if(v.size() > k) for(int i=0 ; i<v.size() - k ; ++i) res += v[i];

        if(res <= g) ans = max(ans, m), l = m + 1;
        else r = m - 1;
    } cout << ans;

    return 0;
}
