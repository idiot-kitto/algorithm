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

int arr[2020][2020];
vpii v[101010];

int main(){fastio
    int n, k; cin >> n >> k;
    DSU dsu(k);
    for(int i=1 ; i<=k ; ++i) {
        int a, b; cin >> a >> b;
        arr[a][b] = i;
        v[i].pb({a, b});
    }

    for(int i=1 ; i<=n ; ++i) {
        for(int j=1 ; j<=n ; ++j) {
            if(arr[i][j]) {
                for(int k=0 ; k<4 ; ++k) {
                    int nx = i + dir[k][0], ny = j + dir[k][1];
                    if(nx >= 1 && nx <= n && ny >= 1 && ny <= n) 
                        if(arr[nx][ny] && arr[nx][ny] != arr[i][j]) dsu.merge(arr[nx][ny], arr[i][j]);
                }
            }
        }
    }

    int ans = 0;
    while(1) {
        set<int> s;
        for(int i=1 ; i<=k ; ++i) s.insert(dsu.find(i));
        if(s.size() == 1) { cout << ans; return 0;}

        for(int i=1 ; i<=k ; ++i) {
            vpii tmp;
            for(auto p : v[i]) {
                int x = p.first, y = p.second;
                for(int j=0 ; j<4 ; ++j) {
                    int nx = x + dir[j][0], ny = y + dir[j][1];
                    if(nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
                        if(arr[nx][ny] == 0) {
                            arr[nx][ny] = i;
                            tmp.pb({nx, ny});
                            for(int k=0 ; k<4 ; ++k) {
                                int nx2 = nx + dir[k][0], ny2 = ny + dir[k][1];
                                if(nx2 >= 1 && nx2 <= n && ny2 >= 1 && ny2 <= n)
                                    if(arr[nx2][ny2] && arr[nx2][ny2] != i) dsu.merge(arr[nx2][ny2], i);
                            }
                        }
                    }
                }
            } v[i].clear(); v[i] = tmp;
        } ans++;
    }

    return 0;
}