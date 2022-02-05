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

ll arr[10] = {0, 0, 1, 7, 4, 2, 0, 8, 10};
ll dp[101];

int main(){fastio
    for(int i=1 ; i<=9 ; ++i) dp[i] = arr[i]; dp[6] = 6;
    for(int i=9 ; i<=100 ; ++i) {
        dp[i] = 1e18;
        for(int j=2 ; j<=7 ; ++j) dp[i] = min(dp[i], dp[i - j] * 10 + arr[j]);
    }

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        cout << dp[n] << ' ';
        while(n) {
            if(n & 1) { cout << 7; n -= 3; }
            else { cout << 1; n -= 2; }
        } cout << '\n';
    }
    return 0;
}