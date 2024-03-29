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
    ll n; cin >> n; vl v(n+1, 0);
    for(ll i=1 ; i<=n ; i++) cin >> v[i];
    sort(++v.begin(), v.end());
    ll ans = 0, cnt = 0, sum = 0, tmp = 0;

    vl vv; // 음수
    for(ll i=1 ; i<=n ; i++) {
        if(v[i] < 0) {
            tmp += v[i];
            vv.pb(v[i]);
        } else {
            cnt++;
            sum += v[i];
        }
    } ans = max(ll(-1e16), sum * cnt + tmp);

    sort(all(vv));
    reverse(all(vv));

    for(ll i=0 ; i<vv.size() ; i++) {
        cnt++;
        sum += vv[i];
        tmp -= vv[i];
        ans = max(ans, sum * cnt + tmp);
    }

    cout << ans;

    return 0;
}

// -1 2 2 -> 9
