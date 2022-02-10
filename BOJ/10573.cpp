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

ll dp[10][82];

int main(){fastio
    for(int i=1 ; i<=9 ; ++i) dp[i][1] = 1;
    for(int i=2 ; i<82 ; ++i)
        for(int j=1 ; j<=9 ; ++j)
            for(int k=j ; k<=9 ; ++k)
                dp[j][i] += dp[k][i-1];

    int t; cin >> t;
    while(t--) {
        string s; cin >> s; int l = (int)s.size(); bool ok = true;
        for(int i=0 ; i<s.size()-1 ; ++i) if(s[i+1] < s[i]) ok = false;
        if(!ok) { cout << -1 << '\n'; continue; }

        ll ans = 0;
        for(int i=0 ; i<l ; ++i) {
            int n = s[i] - '0';
            ans += dp[1][l+1-i];
            if(n != 9) ans -= dp[n+1][l+1-i];
        } cout << ans << '\n';
    }
    return 0;
}