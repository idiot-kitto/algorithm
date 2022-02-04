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

int n, m;
int arr[1010][1010], check[1010][1010], ans[1010][1010], v[1010101];

int bfs(int x, int y, int k) {
    queue<pii> q;
    q.push({x, y});
    check[x][y] = k;
    int cnt = 0;
    while(!q.empty()) {
        cnt++;
        int cx = q.front().first, cy = q.front().second; q.pop();
        for(int i=0 ; i<4 ; ++i) {
            int nx = cx + dir[i][0], ny = cy + dir[i][1];
            if(nx >= 1 && nx <= n && ny >= 1 && ny <= m) {
                if(!arr[nx][ny] && !check[nx][ny]) {
                    q.push({nx, ny});
                    check[nx][ny] = k;
                }
            }
        }
    } return cnt;
}

int main(){fastio
    cin >> n >> m;
    for(int i=1 ; i<=n ; ++i) {
        string s; cin >> s;
        for(int j=1 ; j<=m ; ++j) arr[i][j] = s[j-1] - '0';
    }

    int val = 1;
    for(int i=1 ; i<=n ; ++i) 
        for(int j=1 ; j<=m ; ++j) 
            if(!arr[i][j] && !check[i][j]) 
                v[val] = bfs(i, j, val), val++;

    for(int i=1 ; i<=n ; ++i) {
        for(int j=1 ; j<=m ; ++j) {
            if(arr[i][j]) {
                ans[i][j] = 1;
                vi tmp;
                for(int k=0 ; k<4 ; ++k) {
                    int nx = i + dir[k][0], ny = j + dir[k][1];
                    if(nx >= 1 && nx <= n && ny >= 1 && ny <= m) tmp.pb(check[nx][ny]);
                } 
                sort(all(tmp));
                tmp.erase(unique(all(tmp)), tmp.end());
                for(auto idx : tmp) ans[i][j] += v[idx];
            }
        }
    }

    for(int i=1 ; i<=n ; ++i) {
        for(int j=1 ; j<=m ; ++j) cout << ans[i][j] % 10;
        cout << '\n';
    }

    return 0;
}