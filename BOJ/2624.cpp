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

int dp[101][10101];

int main(){fastio
    int t, k; cin >> t >> k; vpii v(1);
    for(int i=0 ; i<k ; ++i) {
        int a, b; cin >> a >> b;
        v.pb({a, b});
    } sort(++v.begin(), v.end());
    dp[0][0] = 1;
    for(int i=1 ; i<=k ; ++i) {
        for(int j=0 ; j<=v[i].second ; ++j) { // 동전 개수
            for(int l=0 ; l<=t ; ++l) { // 값
                int prev = j * v[i].first;
                if(prev + l > t) break;
                dp[i][prev + l] += dp[i-1][l];
            }
        }
    } cout << dp[k][t];

    return 0;
}