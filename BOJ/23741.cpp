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

int n, m, x, y;
vi v[1010];
bool arr[1010][1010];

int main(){fastio
    cin >> n >> m >> x >> y;
    for(int i=0 ; i<m ; ++i) {
        int a, b; cin >> a >> b;
        v[a].pb(b); v[b].pb(a);
    }

    queue<pii> q;
    
    q.push({x,0});
    arr[x][0] = true;
    
    while(!q.empty()) {
        int num = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if(cnt == y) continue;
        for(auto next : v[num]) {
            if(arr[next][cnt + 1]) continue;
            arr[next][cnt + 1] = true;
            q.push({next, cnt + 1});
        }
    }

    bool ok = true;
    for(int i=1 ; i<=n ; ++i) {
        if(arr[i][y]) { cout << i << ' '; ok = false; }
    } if(ok) cout << -1;

    return 0;
}

// dfs로 짜면 벡터에 너무 많이 들어가는 데이터때문에 RTE(bad_alloc)뜸.
