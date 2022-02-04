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
char arr[1010][1010];
vector<vector<char>> stamp[505];

int main(){fastio
    cin >> n >> m;
    for(int i=0 ; i<n ; ++i) for(int j=0 ; j<m ; ++j) arr[i][j] = '.';
        
    int k; cin >> k;
    for(int a=1 ; a<=k ; ++a) {
        int h, w; cin >> h >> w;
        vector<vector<char>> tmp(h, vector<char>(w));
        
        for(int i=0 ; i<h ; ++i) {
            string s; cin >> s;
            for(int j=0 ; j<w ; ++j) tmp[i][j] = s[j];
        } stamp[a] = tmp;
    }
    
    int q; cin >> q;
    while(q--) {
        int t, y, x; cin >> t >> y >> x;
        vector<vector<char>> tmp = stamp[t];
        for(int i=y ; i<y+tmp.size() ; ++i) {
            for(int j=x ; j<x+tmp[0].size() ; ++j) {
                arr[i][j] = tmp[i-y][j-x];
            }
        }
    }

    for(int i=0 ; i<n ; ++i) {
        for(int j=0 ; j<m ; ++j) cout << arr[i][j];
        cout << '\n';
    }

    return 0;
}