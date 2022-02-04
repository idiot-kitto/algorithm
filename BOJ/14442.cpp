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

int n, m, k, arr[1010][1010], check[1010][1010][11];

void bfs() {
    queue<tuple<int, int, int>> q;
    check[1][1][0] = 1;
    q.emplace(1, 1, 0);
    while(!q.empty()) {
        int cx = get<0>(q.front()), cy = get<1>(q.front()), block = get<2>(q.front()); q.pop();
        for(int i=0 ; i<4 ; ++i) {
            int nx = cx + dir[i][0], ny = cy + dir[i][1];
            if(nx >= 1 && nx <= n && ny >= 1 && ny <= m) {
                if(arr[nx][ny] == 0 && !check[nx][ny][block]) {
                    check[nx][ny][block] = check[cx][cy][block] + 1;
                    q.emplace(nx, ny, block);
                }
                if(arr[nx][ny] == 1 && !check[nx][ny][block + 1]) {
                    if(block < k) {
                        check[nx][ny][block + 1] = check[cx][cy][block] + 1;
                        q.emplace(nx, ny, block + 1);
                    }
                }
            }
        }
    }
}

int main(){fastio
    cin >> n >> m >> k;
    for(int i=1 ; i<=n ; ++i) {
        string s; cin >> s;
        for(int j=1 ; j<=m ; ++j) arr[i][j] = s[j-1] - '0';
    } bfs();

    int ans = 1e9;
    for(int i=0 ; i<11 ; ++i) if(check[n][m][i]) ans = min(ans, check[n][m][i]);
    cout << (ans == 1e9 ? -1 : ans);

    return 0;
}