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

int arr[510][510];

int main(){fastio
    int n, m; cin >> n >> m;
    while(m--){
        int a, b; cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = -1;
    }

    for(int k=1 ; k<=n ; k++)
        for(int i=1 ; i<=n ; i++)
            for(int j=1 ; j<=n ; j++){
                if(arr[i][k] == arr[k][j]){
                    if(arr[i][k] == 1) arr[i][j] = 1;
                    else if(arr[i][k] == -1) arr[i][j] = -1;
                }
            }

    int ans = 0;
    for(int i=1 ; i<=n ; i++){
        bool ok = true;
        for(int j=1 ; j<=n ; j++){
            if(i == j) continue;
            if(arr[i][j] == 0) ok = false;
        }if(ok) ans++;
    }cout << ans;

    return 0;
}
