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
int n;
ll dp[35][35][3];
int main(){fastio
    cin >> n; vvl v(n+1,vl(n+1));
    for(int i=1 ; i<=n ; i++)
        for(int j=1 ; j<=n ; j++) cin >> v[i][j];
    dp[1][2][0] = 1;
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=n ; j++){
            if(i == 1 && j == 1) continue;
            if(v[i][j]) continue;
            if(j+1 <= n && !v[i][j+1]) dp[i][j+1][0] = dp[i][j][0] + dp[i][j][2];
            if(i+1 <= n && !v[i+1][j]) dp[i+1][j][1] = dp[i][j][1] + dp[i][j][2];
            if(i+1 <= n && j+1 <= n && !v[i][j+1] && !v[i+1][j] && !v[i+1][j+1])
                dp[i+1][j+1][2] = dp[i][j][0] + dp[i][j][1] + dp[i][j][2];
        }
    } cout << dp[n][n][0] + dp[n][n][1] + dp[n][n][2];
    return 0;
}

// 파이프 옮기기 1, 2 둘 다 AC
