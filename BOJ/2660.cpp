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

ll d[55][55];

int main(){fastio
    ll n; cin >> n;

    for(int i=0 ; i<55 ; i++)
        for(int j=0 ; j<55 ; j++) d[i][j] = INT_MAX;

    while(1) {
        int a, b; cin >> a >> b;
        if(a == -1 && b == -1) break;
        d[a][b] = 1;
        d[b][a] = 1;
    }

    for(int k=1 ; k<=n ; k++)
        for(int i=1 ; i<=n ; i++)
            for(int j=1 ; j<=n ; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    for(int i=1 ; i<=n ; i++) d[i][i] = 0;

    vl vv;
    ll mn = INT_MAX;
    for(int i=1 ; i<=n ; i++){
        ll tmp = 0;
        for(int j=1 ; j<=n ; j++) tmp = max(tmp, d[i][j]);

        if(tmp < mn) {
            mn = tmp;
            vv.clear();
            vv.pb(i);
        } else if(tmp == mn) {
            vv.pb(i);
        }
    }

    cout << mn << ' ' << vv.size() << '\n';
    for(int i=0 ; i<vv.size() ; i++) cout << vv[i] << ' ';

    return 0;
}
