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


int main(){fastio
    int t; cin >> t;
    while(t--) {
        int n, p, q; cin >> n >> p >> q;
        ll d[p+1][p+1];
        for(int i=1 ; i<=p ; i++)
            for(int j=1 ; j<=p ; j++){
                if(i == j) d[i][j] = 0;
                else d[i][j] = 1e8;
            }

        vi v;
        for(int i=1 ; i<=n ; i++) {
            int a; cin >> a;
            v.pb(a);
        }

        for(int i=1 ; i<=q ; i++) {
            ll a, b, c; cin >> a >> b >> c;
            d[a][b] = min(d[a][b], c);
            d[b][a] = min(d[a][b], c);
        }

        for(int k=1 ; k<=p ; k++)
            for(int i=1 ; i<=p ; i++)
                for(int j=1 ; j<=p ; j++) {
                    if(i == j || j == k || k == i) continue;
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }

        ll ans = -1, cost = 1e8;
        for(int i=1 ; i<=p ; i++) {
            ll tmp = 0;
            for(int j=0 ; j<v.size() ; j++) {
                tmp += d[i][v[j]] * d[i][v[j]];
            }
            if(ans == -1 || tmp < cost) {
                ans = i;
                cost = tmp;
            }
        }
        cout << ans << ' ' << cost << '\n';
    }

    return 0;
}
