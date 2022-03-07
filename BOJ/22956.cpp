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

vvl h, water;

struct DSU {
    pii sz; vector<vector<pii>> pa;
    DSU(pii _sz):sz(_sz) { 
        pa = vector<vector<pii>>(sz.first+1, vector<pii>(sz.second+1)); 
        for(int i=1 ; i<=sz.first ; ++i) for(int j=1 ; j<=sz.second ; ++j) pa[i][j] = {i, j};
    }
    pii find(pii a){return a == pa[a.first][a.second] ? a : (pa[a.first][a.second] = find(pa[a.first][a.second])); }
    void merge(pii a, pii b){ 
        auto [ax, ay] = find(a); 
        auto [bx, by] = find(b);
        if(h[ax][ay] < h[bx][by]) pa[bx][by] = {ax, ay};
        else if(h[ax][ay] > h[bx][by]) pa[ax][ay] = {bx, by};
        else {
            if(water[ax][ay] < water[bx][by]) pa[bx][by] = {ax, ay};
            else if(water[ax][ay] > water[bx][by]) pa[ax][ay] = {bx, by};
        }
    }
    int check(pii a, pii b){ return find(a) == find(b); }
};

int main(){fastio
    ll n, m, q; cin >> n >> m >> q; h = vvl(n+1, vl(m+1)); water = vvl(n+1, vl(m+1, 0));
    for(int i=1 ; i<=n ; ++i) for(int j=1 ; j<=m ; ++j) cin >> h[i][j];
    DSU dsu({n ,m});
    for(int i=1 ; i<=q ; ++i) {
        ll a, b, c; cin >> a >> b >> c;
        h[a][b] -= c; water[a][b] = i;
        for(int j=0 ; j<4 ; ++j) {
            int na = a + dir[j][0], nb = b + dir[j][1];
            if(na >= 1 && na <= n && nb >= 1 && nb <= m && water[na][nb]) {
                if(dsu.find({a, b}) != dsu.find({na, nb})) dsu.merge({a, b}, {na, nb});
                else {
                    if(h[a][b] < h[na][nb]) {
                        dsu.pa[a][b] = {a,b};
                        dsu.merge({a, b}, {na, nb});
                    } else if(h[a][b] == h[na][nb]) {
                        if(water[a][b] < water[na][nb]) {
                            dsu.pa[a][b] = {a,b};
                            dsu.merge({a, b}, {na, nb});
                        }
                    }
                }
            }
        }
        auto [rx, ry] = dsu.find({a, b});
        cout << rx << ' ' << ry << '\n';
    }
    

    return 0;
}