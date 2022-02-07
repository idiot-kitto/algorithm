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
const int mod = 1e5;
const long double PI = 3.141592653589793238462643383279502884197;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

int dp[101][101][2][2];
// 인자 1, 2 : x, y 좌표
// 인자 3 : 0이면 세로 이동, 1이면 가로 이동
// 인자 4 : 0이면 꺾어서 이동 불가상태 = 꺾어 1칸 이동한 상태
//          1이면 이동 가능상태 = 같은 방향 2칸 이상 이동한 상태

int main(){fastio
    int w, h; cin >> w >> h;
    for(int i=1 ; i<=w ; ++i) dp[i][1][0][1] = 1; // 세로
    for(int i=1 ; i<=h ; ++i) dp[1][i][1][1] = 1; // 가로

    for(int i=2 ; i<=w ; ++i) {
        for(int j=2 ; j<=h ; ++j) {
            dp[i][j][0][0] = dp[i-1][j][1][1];
            dp[i][j][1][0] = dp[i][j-1][0][1];
            // 인자 4가 0 : 꺾어서 1번 이동한 상태이므로 이전 값은 2칸 이동한 다른 방향 값
            dp[i][j][0][1] = (dp[i-1][j][0][0] + dp[i-1][j][0][1]) % mod;
            dp[i][j][1][1] = (dp[i][j-1][1][0] + dp[i][j-1][1][1]) % mod;
            // 인자 4가 1 : 같은 방향 2칸 이동한 상태이므로 이전 값은 같은 방향 1칸 or 2칸 이상 이동한 상태 값
        }
    }

    int ans = 0;
    for(int i=0 ; i<2 ; ++i) for(int j=0 ; j<2 ; ++j) ans += dp[w][h][i][j], ans %= mod;
    cout << ans;

    return 0;
}