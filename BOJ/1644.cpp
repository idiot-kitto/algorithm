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
const long long mod = 1e9 + 7;
const long double PI = 3.141592653589793238462643383279502884197;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

int main(){fastio
    ll n; cin >> n;
    if(n == 1) { cout << 0; return 0; }
    ll ans = 0;

    vb vv(n+1, true);
    for(ll i=2 ; i*i <= n ; ++i) {
        if(vv[i]) for(ll j=i+i ; j<=n ; j+=i) vv[j] = false;
    }

    vl v;
    for(ll i=2 ; i<=n ; ++i) if(vv[i]) v.pb(i);

    ll l = 0, r = 0;
    ll tmp = 0;
    while(1) {
        if(l > r) break;
        if(r > (ll)v.size()) break;

        if(tmp == n) {
            tmp += v[r++];
            ans++;
        }
        else if(tmp > n) tmp -= v[l++];
        else if(tmp < n) tmp += v[r++];
    }

    cout << ans;

    return 0;
}
