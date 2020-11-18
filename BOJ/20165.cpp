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
int n, m, r, ans;
vvi v;
vector<vc> vv;

int solve(int x, int y, char d){
    if(vv[x][y] == 'F') return 0;

    int k = 0; queue<pii> q;
    q.push({x,y});

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        if(vv[cx][cy] == 'S'){vv[cx][cy] = 'F'; k++;}
        else continue;

        if(d == 'E'){
            int ny = cy + v[x][cy];
            for(int i=cy+1 ; i<ny ; i++)
                if(i>=1 && i<=m && vv[x][i] == 'S')
                    q.push({x,i});
        }
        else if(d == 'W'){
            int ny = cy - v[x][cy];
            for(int i=cy-1 ; i>ny ; i--)
                if(i>=1 && i<=m && vv[x][i] == 'S')
                    q.push({x,i});
        }
        else if(d == 'S'){
            int nx = cx + v[cx][y];
            for(int i=cx+1 ; i<nx ; i++)
                if(i>=1 && i<=n && vv[i][y] == 'S')
                    q.push({i,y});
        }
        else if(d == 'N'){
            int nx = cx - v[cx][y];
            for(int i=cx-1 ; i>nx ; i--)
                if(i>=1 && i<=n && vv[i][y] == 'S')
                    q.push({i,y});
        }
    } return k;
}

int main(){fastio
    cin >> n >> m >> r; v = vvi(n+1,vi(m+1)); vv = vector<vc>(n+1,vc(m+1));
    for(int i=1 ; i<=n ; i++)
        for(int j=1 ; j<=m ; j++){cin >> v[i][j]; vv[i][j] = 'S';}
    for(int i=0 ; i<r ; i++){
        int x, y; char d; cin >> x >> y >> d;
        ans += solve(x,y,d);
        int a, b; cin >> a >> b;
        vv[a][b] = 'S';
    }cout << ans << '\n';
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=m ; j++) cout << vv[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}
