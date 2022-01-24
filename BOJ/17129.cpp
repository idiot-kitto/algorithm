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

int arr[3030][3030], check[3030][3030];

int main(){fastio
    int n, m; cin >> n >> m;
    int sx, sy;
    for(int i=1 ; i<=n ; ++i) {
        string s; cin >> s;
        for(int j=1 ; j<=m ; ++j) {
            arr[i][j] = s[j-1] - '0';
            if(arr[i][j] == 2) sx = i, sy = j;
        }
    }
    queue<pii> q; q.push({sx, sy}); check[sx][sy] = 1;
    while(!q.empty()) {
        int cx = q.front().first, cy = q.front().second; q.pop();
        for(int i=0 ; i<4 ; ++i) {
            int nx = cx + dir[i][0], ny = cy + dir[i][1];
            if(nx >= 1 && nx <= n && ny >= 1 && ny <= m) {
                if(arr[nx][ny] != 1 && !check[nx][ny]) {
                    if(arr[nx][ny] > 1) {
                        cout << "TAK\n" << check[cx][cy];
                        return 0;
                    }
                    q.push({nx, ny});
                    check[nx][ny] = check[cx][cy] + 1;
                }
            }
        }
    } cout << "NIE";
    
    return 0;
}