#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define SIZE 100001

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

ll d[202][202];

int main(){fastio
    ll n, m; cin >> n >> m;
    for(int i=0 ; i<202 ; i++) for(int j=0 ; j<202 ; j++) d[i][j] = 1e9 + 7;
    while(m--){
        int a, b, c; cin >> a >> b >> c;
        d[a][b] = c;
        d[b][a] = c;
    }

    for(int k=1 ; k<=n ; k++)
        for(int i=1 ; i<=n ; i++)
            for(int j=1 ; j<=n ; j++){
                if(i == j || j == k || k == i) continue;
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }

    int ans = -1, tot;
    for(int i=1 ; i<=n ; i++) {
        int tmp = 0;
        for(int j=1 ; j<=n ; j++)
            if(i != j) {
                tmp += d[i][j];
            }
        if(tmp < tot || ans == -1) {
            ans = i;
            tot = tmp;
        }
    }
    cout << ans;

    return 0;
}
