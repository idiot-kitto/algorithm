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

int arr[1010101], check[1010101];

int main(){fastio
    int f, s, g, u, d; cin >> f >> s >> g >> u >> d;
    for(int i=0 ; i<1010101 ; ++i) arr[i] = 1e9;
    arr[s] = 0, check[s] = 1;
    queue<int> q; q.push(s);
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(int i=0 ; i<2 ; ++i) {
            int next;
            if(!i) next = cur + u;
            else next = cur - d;
            if(next >= 1 && next <= f && !check[next]) {
                check[next] = 1;
                arr[next] = arr[cur] + 1;
                q.push(next);
            }
        }
    }
    if(arr[g] == 1e9) cout << "use the stairs";
    else cout << arr[g];

    return 0;
}