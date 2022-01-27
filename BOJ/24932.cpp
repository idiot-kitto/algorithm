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
int dir[3][2] = {{-1,0}, {-1,-1}, {-1,1}};

int arr[1010][1010];
ll v[1010][1010];

int main(){fastio
    int n, m; cin >> n >> m;
    for(int i=1 ; i<=n ; ++i) for(int j=1 ; j<=m ; ++j) cin >> arr[i][j];
    for(int i=1 ; i<=m ; ++i) v[n][i] = (ll)arr[n][i];

    for(int i=n ; i>1 ; --i) {
        for(int j=1 ; j<=m ; ++j) {
            if(arr[i][j]) {
                for(int k=0 ; k<3 ; ++k) {
                    int nx = i + dir[k][0], ny = j + dir[k][1];
                    if(nx >= 1 && ny >= 1 && ny <= m) {
                        if(arr[nx][ny]) {
                            v[nx][ny] += v[i][j];
                            v[nx][ny] %= mod;
                        }
                    }
                }
            }
        }
    }
    ll ans = 0;
    for(int i=1 ; i<=m ; ++i) { ans += v[1][i]; ans %= mod; }
    cout << ans;
    
    return 0;
}