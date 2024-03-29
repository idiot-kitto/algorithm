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
 
char arr[55][55];
 
int main(){fastio
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k; vi v(n+1);
        for(int i=1 ; i<=n ; ++i) cin >> v[i];
 
        if(n <= k) {
            for(int i=30 ; i>=0 ; --i) {
                for(int j=1 ; j<=n ; ++j) {
                    if(!(1<<i & v[j])) { k--; v[j] |= 1<<i; }
                }
                if(n > k) break;
            }
        }
 
        for(int i=30 ; i>=0 ; --i) {
            int cnt = 0;
            for(int j=1 ; j<=n ; ++j) {
                if(!(1<<i & v[j])) cnt++;
            }
            if(cnt <= k) {
                for(int j=1 ; j<=n ; ++j) v[j] |= 1<<i;
                k -= cnt;
            }
        }
 
        int ans = v[1];
        for(int i=2 ; i<=n ; ++i) ans &= v[i];
        cout << ans << '\n';
    }
 
    return 0;
}