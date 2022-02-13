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

struct DSU {
    int n; vi pa;
    DSU(int _n):n(_n) { pa.resize(n+1); iota(all(pa), 0); }
    int find(int a) { return a == pa[a] ? a : (pa[a] = find(pa[a])); }
    void merge(int a, int b) { pa[find(b)] = find(a); }
    int check(int a, int b) { return find(a) == find(b); }
};

int arr[2020][2020], check[2020][2020];
int arr2[2020][2020], check2[2020][2020];
int n, m;
vpii v[1010101];

void bfs(int x, int y, int k) {
    queue<pii> q;
    q.push({x, y});
    check[x][y] = k;
    v[k].pb({x, y});
    while(!q.empty()) {
        int cx = q.front().first, cy = q.front().second; q.pop();
        for(int i=0 ; i<4 ; ++i) {
            int nx = cx + dir[i][0], ny = cy + dir[i][1];
            if(nx >= 1 && nx <= n && ny >= 1 && ny <= m) {
                if(arr[nx][ny] == 0 && check[nx][ny] == 0) {
                    check[nx][ny] = k;
                    q.push({nx, ny});
                    v[k].pb({nx, ny});
                }
            }
        }
    }
}

void bfs2(int x, int y, int k) {
    queue<pii> q;
    q.push({x, y});
    check2[x][y] = 1;
    while(!q.empty()) {
        int cx = q.front().first, cy = q.front().second; q.pop();
        for(int i=0 ; i<4 ; ++i) {
            int nx = cx + dir[i][0], ny = cy + dir[i][1];
            if(nx >= 1 && nx <= n && ny >= 1 && ny <= m) {
                if(arr[nx][ny] != 2 && !check2[nx][ny]) {
                    check2[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }
}

int main(){fastio
    cin >> n >> m;
    bool ok = true;
        
    for(int i=1 ; i<=n ; ++i) {
        string s; cin >> s;
        for(int j=1 ; j<=m ; ++j) {
            arr[i][j] = s[j-1] - '0';
            if(s[j-1] == '0') ok = false;
        }
    } if(ok) { cout << "0 0"; return 0; }

    int cnt = 1;
    for(int i=1 ; i<=n ; ++i) 
        for(int j=1 ; j<=m ; ++j) 
            if(arr[i][j] == 0 && !check[i][j]) bfs(i, j, cnt++);

    int cnt2 = 0;
    for(int i=1 ; i<=n ; ++i) 
        for(int j=1 ; j<=m ; ++j) 
            if(arr[i][j] == 0 && !check2[i][j]) bfs2(i, j, cnt2++);

    DSU dsu(cnt - 1);

    int time = 0, ans = 0;
    while(1) {
        // 모든 불 합쳐졌는지 확인
        set<int> s;
        for(int i=1 ; i<cnt ; ++i) s.insert(dsu.find(i));
        if(s.size() == cnt2) {
            for(int i=1 ; i<=n ; ++i) 
                for(int j=1 ; j<=m ; ++j) 
                    if(check[i][j] == 0) ans++;
            cout << time << ' ' << n * m - ans; return 0;
        }
        // 불 전이
        for(int i=1 ; i<cnt ; ++i) {
            vpii tmp;
            for(auto p : v[i]) {
                int x = p.first, y = p.second;
                for(int j=0 ; j<4 ; ++j) {
                    int nx = x + dir[j][0], ny = y + dir[j][1];
                    if(nx >= 1 && nx <= n && ny >= 1 && ny <= m) {
                        if(arr[nx][ny] == 1 && check[nx][ny] == 0) {
                            check[nx][ny] = i;
                            tmp.pb({nx, ny});
                            for(int k=0 ; k<4 ; ++k) {
                                int nx2 = nx + dir[k][0], ny2 = ny + dir[k][1];
                                if(nx2 >= 1 && nx2 <= n && ny2 >= 1 && ny2 <= m)
                                    if(check[nx2][ny2] && check[nx2][ny2] != i) dsu.merge(check[nx2][ny2], i);
                            }
                        }
                    }
                }
            } v[i].clear(); v[i] = tmp;
        } time++;
    }

    return 0;
}

