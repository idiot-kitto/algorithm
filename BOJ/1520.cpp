#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define SIZE 100001

typedef long long ll;
typedef vector<int> vi;
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
const int mod = 1e9 + 7;
const long double PI = 3.141592653589793238462643383279502884197;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

/* seg_tree
ll tree[4*SIZE];
ll init(ll node, ll start, ll end){
    ll mid = (start + end) / 2;
    if(start == end) return tree[node] = v[start];
    else return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}
void update(ll node, ll start, ll end, ll index, ll diff) {
	if (index < start || index > end) return;
	tree[node] = tree[node] + diff;
	if (start != end) {
		update(node * 2, start, (start + end) / 2, index, diff);
		update(node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
	}
}
long long sum(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[node];
    return sum(node * 2, start, (start + end) / 2, left, right) + sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}*/
int n, m;
vvi v(501,vi(501)), dp(501,vi(501));
int dfs(int x, int y)
{
    if(x == n && y == m) return 1;
    if(dp[x][y] != -1) return dp[x][y];
    dp[x][y] = 0;
    for(int i=0 ; i<4 ; i++){
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if(nx>0 && nx<=n && ny>0 && ny<=m && v[x][y] > v[nx][ny])
            dp[x][y] += dfs(nx,ny);
    }
    return dp[x][y];
}
int main(){fastio
    cin >> n >> m;
    for(int i=1 ; i<=n ; i++)
        for(int j=1 ; j<=m ; j++) cin >> v[i][j];
    for(int i=0 ; i<501 ; i++)
        for(int j=0 ; j<501 ; j++) dp[i][j] = -1;
    cout << dfs(1,1);
    return 0;
}
