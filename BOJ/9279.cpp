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

vi v[1010];
int dp[1010], arr[1010][1010];
bool check[1010];

void go(int n) {
    if(check[n]) return;
    check[n] = true;

    for(auto next : v[n]) {
        if(check[next]) continue;
        go(next);
        if(dp[next]) dp[n] += min(arr[n][next], dp[next]);
        else dp[n] += arr[n][next];
    }
}

int main(){fastio
    while(1) {
        if(cin.eof() == true) break;

        for(int i=0 ; i<1010 ; ++i) {
            v[i].clear();
            dp[i] = 0;
            for(int j=0 ; j<1010 ; ++j) arr[i][j] = 0;
            check[i] = false;
        }
        int n, c; cin >> n >> c;
        for(int i=0 ; i<n-1 ; ++i) {
            int a, b, c; cin >> a >> b >> c;
            v[a].pb(b); v[b].pb(a);
            arr[a][b] = c; arr[b][a] = c;
        } go(c);
        if(dp[c]) cout << dp[c] << '\n';
    }

    return 0;
}
