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

int arr[1010][1010], check[1010][1010], ans[1010][1010];

int main(){fastio
    int n, m; cin >> n >> m;
    int sx, sy;
    for(int i=1 ; i<=n ; ++i) for(int j=1 ; j<=m ; ++j) { cin >> arr[i][j]; if(arr[i][j] == 2) sx = i, sy = j; }

    check[sx][sy] = 1;
    queue<pll> q; q.push({sx, sy});
    while(!q.empty()) {
        int cx = q.front().first, cy = q.front().second; q.pop();
        for(int i=0 ; i<4 ; ++i) {
            int nx = cx + dir[i][0], ny = cy + dir[i][1];
            if(nx >= 1 && nx <= n && ny >= 1 && ny <= m) {
                if(!check[nx][ny] && arr[nx][ny] == 1) {
                    q.push({nx, ny});
                    check[nx][ny] = 1;
                    ans[nx][ny] = ans[cx][cy] + 1;
                }
            }
        }
    }

    for(int i=1 ; i<=n ; ++i) {
        for(int j=1 ; j<=m ; ++j) {
            if(arr[i][j] == 1 && ans[i][j] == 0) cout << -1 << ' ';
            else cout << ans[i][j] << ' ';
        } cout << '\n';
    }

    return 0;
}
