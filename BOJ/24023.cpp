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
    int n, k; cin >> n >> k;
    vi v(n+1);
    for(int i=1 ; i<=n ; ++i) cin >> v[i];

    int val = 0, s = 1;
    for(int i=1 ; i<=n ; ++i) {
        if((v[i] | k) != k) val = 0, s = i + 1;
        else {
            val |= v[i];
            if(val == k) {
                cout << s << ' ' << i << '\n';
                return 0;
            }
        }
    } cout << -1;

    return 0;
}
