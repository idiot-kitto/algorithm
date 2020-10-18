#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define SIZE 100010

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, int> psi;
typedef pair<int, string> pis;
typedef pair<char, int> pci;
typedef pair<int, char> pic;
const int mod = 1e9 + 7;
const long double PI = 3.141592653589793238462643383279502884197;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

int v, ans, e;
vector<pii> node[SIZE];
int visited[SIZE];

void dfs(int p, int l)
{
    if(visited[p]) return;
    visited[p] = 1;
    if(ans < l){ans = l; e = p;}
    for(int i=0 ; i<node[p].size() ; i++)
        dfs(node[p][i].first, l + node[p][i].second);
}

int main(){fastio
    cin >> v;
    for(int i=0 ; i<v; ++i){
        int a; cin >> a;
        while(1){
            int b,c; cin >> b;
            if(b == -1) break;
            cin >> c;
            node[a].pb({b,c});
        }
    }
    dfs(1,0);
    ans = 0;
    memset(visited,0,sizeof(visited));
    dfs(e,0);
    cout << ans;

    return 0;
}
