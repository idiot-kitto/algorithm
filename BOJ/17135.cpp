#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define pb push_back

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

vvi v, vv;
int n, m, d;

pii func(int x, int y){
    for(int i=1 ; i<=d ; i++){
        for(int j=1 ; j<=i ; j++){
            int nx = x-j;
            int ny = y-(i-j);
            if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && vv[nx][ny] == 1) return {nx,ny};
        }
        for(int j=i-1 ; j>=1 ; j--){
            int nx = x-j;
            int ny = y+(i-j);
            if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && vv[nx][ny] == 1) return {nx,ny};
        }
    }return {0,0};
}

int main(){fastio
    cin >> n >> m >> d; v = vvi(n+2, vi(m+1, 0)); vv = v;
    for(int i=1 ; i<=n ; i++)
        for(int j=1 ; j<=m ; j++) cin >> v[i][j];

    int ans = 0;
    vi idx;
    for(int i=0 ; i<3 ; i++) idx.pb(0);
    for(int i=0 ; i<m-3 ; i++) idx.pb(1);
    do{
        vi arrow; int cnt = 0;
        for(int i=1 ; i<=m ; i++) v[n+1][i] = 0;
        for(int i=0 ; i<m ; i++) if(!idx[i]) v[n+1][i+1] = 2, arrow.pb(i+1);
        vv = v;
        int k = n;
        while(k--){
            pii left1 = func(n+1,arrow[0]);
            pii left2 = func(n+1,arrow[1]);
            pii left3 = func(n+1,arrow[2]);
            map<pii,int> mp;
            if(left1.first && left1.second) {mp[left1]++; vv[left1.first][left1.second] = 0;}
            if(left2.first && left2.second) {mp[left2]++; vv[left2.first][left2.second] = 0;}
            if(left3.first && left3.second) {mp[left3]++; vv[left3.first][left3.second] = 0;}
            cnt += mp.size();
            for(int i=n ; i>=1 ; i--) for(int j=1 ; j<=m ; j++) vv[i][j] = vv[i-1][j];
        } ans = max(ans, cnt);
    }while(next_permutation(all(idx)));
    cout << ans;
    return 0;
}
