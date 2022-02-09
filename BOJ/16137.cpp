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

int n, m, ans = 1e9;
int arr[11][11], tmp[11][11], check[11][11];

void bfs() {
    queue<tuple<int, int, int>> q;
    q.emplace(1, 1, 0);
    check[0][0] = 1;
    while(!q.empty()) {
        int cx = get<0>(q.front()), cy = get<1>(q.front()), val = get<2>(q.front()); q.pop();
        if(cx == n && cy == n) { ans = min(ans, val); continue; }
        for(int i=0 ; i<4 ; ++i) {
            int nx = cx + dir[i][0], ny = cy + dir[i][1];
            if(nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
                if(!check[nx][ny]) {
                    if(arr[nx][ny] == 1) {
                        q.emplace(nx, ny, val + 1);
                        check[nx][ny] = 1;
                    } else if(arr[nx][ny] > 1) {
                        if((val + 1) % arr[nx][ny] == 0) {
                            if(arr[cx][cy] == 1) {
                                check[nx][ny] = 1;
                                q.emplace(nx, ny, val + 1);
                            }
                        } else q.emplace(cx, cy, val + 1);
                    }
                }
            }
        }
    }
}

int main(){fastio
    cin >> n >> m;
    for(int i=1 ; i<=n ; ++i) for(int j=1 ; j<=n ; ++j) cin >> arr[i][j], tmp[i][j] = arr[i][j];
    for(int i=2 ; i<n ; ++i) {
        for(int j=2 ; j<n ; ++j) {
            if(tmp[i][j] == 0){
                if(tmp[i-1][j] == 0 && tmp[i][j-1] == 0) arr[i][j] = -1;
                if(tmp[i-1][j] == 0 && tmp[i][j+1] == 0) arr[i][j] = -1;
                if(tmp[i+1][j] == 0 && tmp[i][j-1] == 0) arr[i][j] = -1;
                if(tmp[i+1][j] == 0 && tmp[i][j+1] == 0) arr[i][j] = -1;
            }
        }
    }
    if(tmp[1][n] == 0 && tmp[2][n] == 0 && tmp[1][n+1] == 0) arr[1][n] = -1;
    if(tmp[n][1] == 0 && tmp[n-1][1] == 0 && tmp[n][2] == 0) arr[n][1] = -1;
    for(int i=2 ; i<n ; ++i) if(tmp[1][i] == 0 && tmp[2][i] == 0 && (tmp[1][i+1] == 0 || tmp[1][i-1] == 0)) arr[1][i] = -1;
    for(int i=2 ; i<n ; ++i) if(tmp[n][i] == 0 && tmp[n-1][i] == 0 && (tmp[n][i+1] == 0 || tmp[n][i-1] == 0)) arr[n][i] = -1;
    for(int i=2 ; i<n ; ++i) if(tmp[i][1] == 0 && tmp[i][2] == 0 && (tmp[i-1][1] == 0 || tmp[i+1][1] == 0)) arr[i][1] = -1;
    for(int i=2 ; i<n ; ++i) if(tmp[i][n] == 0 && tmp[i][n-1] == 0 && (tmp[i-1][n] == 0 || tmp[i+1][n] == 0)) arr[i][n] = -1;

    for(int i=1 ; i<=n ; ++i) {
        for(int j=1 ; j<=n ; ++j) {
            if(arr[i][j] == 0) {
                memset(check, 0, sizeof(check));
                arr[i][j] = m;
                bfs();
                arr[i][j] = 0;
            }
        }
    } cout << ans;

    return 0;
}