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

int arr[101][101];

int main(){fastio
    int n; cin >> n;
    int a, b; cin >> a >> b;
    if(n*n < a+b) { cout << -1; return 0; }
    int aa = a, bb = b, nn = n;

    for(int k=2 ; k<n+2 ; ++k) {
        for(int i=k-1, j=1 ; i+j<=k ; --i, ++j) {
            if(aa && i>=1 && i<=n && j>=1 && j<=n) arr[i][j] = 1, aa--;
            else break;
        }
    }
    for(int k=n+2 ; k<=n*2 ; ++k) {
        for(int i=n, j=k-i ; i+j<=k ; --i, ++j) {
            if(aa && i>=1 && i<=n && j>=1 && j<=n) arr[i][j] = 1, aa--;
            else break;
        }
    }

    for(int k=n*2 ; k>n ; --k) {
        for(int j=n, i=k-j ; i+j<=k ; ++i, --j) {
            if(bb && i>=1 && i<=n && j>=1 && j<=n) arr[i][j] = 2, bb--;
            else break;
        }
    }
    for(int k=n ; k>=2 ; --k) {
        for(int i=1, j=k-i ; i+j<=k ; ++i, --j) {
            if(bb && i>=1 && i<=n && j>=1 && j<=n) arr[i][j] = 2, bb--;
            else break;
        }
    }

    auto check = [&](int x, int y) {
        for(int i=0 ; i<4 ; ++i) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if(arr[x][y] && arr[nx][ny] && nx >= 1 && nx <= n && ny >= 1 && ny <= n && arr[x][y] != arr[nx][ny]) return true;
        } return false;
    };

    for(int i=1 ; i<=n ; ++i) 
        for(int j=1 ; j<=n ; ++j) 
            if(check(i,j)) { cout << -1; return 0; }    

    cout << 1 << '\n';
    for(int i=1 ; i<=n ; ++i) {
        for(int j=1 ; j<=n ; ++j) cout << arr[i][j];
        cout << '\n';
    }
    return 0;
}