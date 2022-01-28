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
int dir[4][2] = {{0,-1},{-1,0},{0,1},{1,0}}; // 서북동남

int arr[55][55], check[55][55], Rcnt, Rmax, Rmax2;
int n, m;

int bfs(int x, int y) {
    queue<pii> q;
    q.push({x, y});
    check[x][y] = 1;
    int Rmaxtmp = 0;
    while(!q.empty()) {
        int cx = q.front().first, cy = q.front().second; q.pop();
        Rmaxtmp++;
        int k = arr[cx][cy];
        for(int i=0 ; i<4 ; ++i) {
            if(!(k & 1)) {
                int nx = cx + dir[i][0], ny = cy + dir[i][1];
                if(nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    if(!check[nx][ny]) {
                        check[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            } k = k >> 1;
        }
    } return Rmaxtmp;
}

int main(){fastio
    cin >> n >> m;
    for(int i=0 ; i<m ; ++i) for(int j=0 ; j<n ; ++j) cin >> arr[i][j];
    for(int i=0 ; i<m ; ++i) for(int j=0 ; j<n ; ++j) if(!check[i][j]) { Rcnt++; Rmax = max(Rmax, bfs(i, j)); }
    for(int i=0 ; i<m ; ++i) for(int j=0 ; j<n ; ++j)
            for(int k=0 ; k<4 ; ++k) {
                if((arr[i][j] >> k) & 1) {
                    memset(check, 0, sizeof(check));
                    int tmp = arr[i][j] - (1 << k);
                    swap(arr[i][j], tmp);
                    Rmax2 = max(Rmax2, bfs(i, j));
                    swap(arr[i][j], tmp);
                }
            }
    cout << Rcnt << '\n' << Rmax << '\n' << Rmax2;
    return 0;
}