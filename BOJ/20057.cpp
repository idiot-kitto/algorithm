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
int n, x, y;
vvi v;
bool inrange(int xx, int yy){
    if(xx>=1 && xx<=n && yy>=1 && yy<=n) return true;
    else return false;
}
void fl(int xx, int yy){
    double val = v[xx][yy]; v[xx][yy] = 0; int tmp = 0;
    if(inrange(xx-1,yy)) v[xx-1][yy] += (int)(floor(val*0.07)); tmp += (int)(floor(val*0.07));
    if(inrange(xx+1,yy)) v[xx+1][yy] += (int)(floor(val*0.07)); tmp += (int)(floor(val*0.07));
    if(inrange(xx-2,yy)) v[xx-2][yy] += (int)(floor(val*0.02)); tmp += (int)(floor(val*0.02));
    if(inrange(xx+2,yy)) v[xx+2][yy] += (int)(floor(val*0.02)); tmp += (int)(floor(val*0.02));
    if(inrange(xx-1,yy+1)) v[xx-1][yy+1] += (int)(floor(val*0.01)); tmp += (int)(floor(val*0.01));
    if(inrange(xx+1,yy+1)) v[xx+1][yy+1] += (int)(floor(val*0.01)); tmp += (int)(floor(val*0.01));
    if(inrange(xx-1,yy-1)) v[xx-1][yy-1] += (int)(floor(val*0.1)); tmp += (int)(floor(val*0.1));
    if(inrange(xx+1,yy-1)) v[xx+1][yy-1] += (int)(floor(val*0.1)); tmp += (int)(floor(val*0.1));
    if(inrange(xx,yy-2)) v[xx][yy-2] += (int)(floor(val*0.05)); tmp += (int)(floor(val*0.05));
    if(inrange(xx,yy-1)) v[xx][yy-1] += (val - tmp);
}
void fd(int xx, int yy){
    double val = v[xx][yy]; v[xx][yy] = 0; int tmp = 0;
    if(inrange(xx,yy-1)) v[xx][yy-1] += (int)(floor(val*0.07)); tmp += (int)(floor(val*0.07));
    if(inrange(xx,yy+1)) v[xx][yy+1] += (int)(floor(val*0.07)); tmp += (int)(floor(val*0.07));
    if(inrange(xx,yy-2)) v[xx][yy-2] += (int)(floor(val*0.02)); tmp += (int)(floor(val*0.02));
    if(inrange(xx,yy+2)) v[xx][yy+2] += (int)(floor(val*0.02)); tmp += (int)(floor(val*0.02));
    if(inrange(xx-1,yy-1)) v[xx-1][yy-1] += (int)(floor(val*0.01)); tmp += (int)(floor(val*0.01));
    if(inrange(xx-1,yy+1)) v[xx-1][yy+1] += (int)(floor(val*0.01)); tmp += (int)(floor(val*0.01));
    if(inrange(xx+1,yy-1)) v[xx+1][yy-1] += (int)(floor(val*0.1)); tmp += (int)(floor(val*0.1));
    if(inrange(xx+1,yy+1)) v[xx+1][yy+1] += (int)(floor(val*0.1)); tmp += (int)(floor(val*0.1));
    if(inrange(xx+2,yy)) v[xx+2][yy] += (int)(floor(val*0.05)); tmp += (int)(floor(val*0.05));
    if(inrange(xx+1,yy)) v[xx+1][yy] += (val - tmp);
}
void fr(int xx, int yy){
    double val = v[xx][yy]; v[xx][yy] = 0; int tmp = 0;
    if(inrange(xx+1,yy)) v[xx+1][yy] += (int)(floor(val*0.07)); tmp += (int)(floor(val*0.07));
    if(inrange(xx-1,yy)) v[xx-1][yy] += (int)(floor(val*0.07)); tmp += (int)(floor(val*0.07));
    if(inrange(xx+2,yy)) v[xx+2][yy] += (int)(floor(val*0.02)); tmp += (int)(floor(val*0.02));
    if(inrange(xx-2,yy)) v[xx-2][yy] += (int)(floor(val*0.02)); tmp += (int)(floor(val*0.02));
    if(inrange(xx+1,yy-1)) v[xx+1][yy-1] += (int)(floor(val*0.01)); tmp += (int)(floor(val*0.01));
    if(inrange(xx-1,yy-1)) v[xx-1][yy-1] += (int)(floor(val*0.01)); tmp += (int)(floor(val*0.01));
    if(inrange(xx+1,yy+1)) v[xx+1][yy+1] += (int)(floor(val*0.1)); tmp += (int)(floor(val*0.1));
    if(inrange(xx-1,yy+1)) v[xx-1][yy+1] += (int)(floor(val*0.1)); tmp += (int)(floor(val*0.1));
    if(inrange(xx,yy+2)) v[xx][yy+2] += (int)(floor(val*0.05)); tmp += (int)(floor(val*0.05));
    if(inrange(xx,yy+1)) v[xx][yy+1] += (val - tmp);
}
void fu(int xx, int yy){
    double val = v[xx][yy]; v[xx][yy] = 0; int tmp = 0;
    if(inrange(xx,yy+1)) v[xx][yy+1] += (int)(floor(val*0.07)); tmp += (int)(floor(val*0.07));
    if(inrange(xx,yy-1)) v[xx][yy-1] += (int)(floor(val*0.07)); tmp += (int)(floor(val*0.07));
    if(inrange(xx,yy+2)) v[xx][yy+2] += (int)(floor(val*0.02)); tmp += (int)(floor(val*0.02));
    if(inrange(xx,yy-2)) v[xx][yy-2] += (int)(floor(val*0.02)); tmp += (int)(floor(val*0.02));
    if(inrange(xx+1,yy+1)) v[xx+1][yy+1] += (int)(floor(val*0.01)); tmp += (int)(floor(val*0.01));
    if(inrange(xx+1,yy-1)) v[xx+1][yy-1] += (int)(floor(val*0.01)); tmp += (int)(floor(val*0.01));
    if(inrange(xx-1,yy+1)) v[xx-1][yy+1] += (int)(floor(val*0.1)); tmp += (int)(floor(val*0.1));
    if(inrange(xx-1,yy-1)) v[xx-1][yy-1] += (int)(floor(val*0.1)); tmp += (int)(floor(val*0.1));
    if(inrange(xx-2,yy)) v[xx-2][yy] += (int)(floor(val*0.05)); tmp += (int)(floor(val*0.05));
    if(inrange(xx-1,yy)) v[xx-1][yy] += (val - tmp);
}

int main(){fastio
    int tot = 0, res = 0; cin >> n; v = vvi(n+1,vi(n+1));
    for(int i=1 ; i<=n ; i++)
        for(int j=1 ; j<=n ; j++){cin >> v[i][j]; tot += v[i][j];}
    x = n/2+1, y = n/2+1;
    int dist = 1;
    while(1){if(dist == n) break;
        for(int j=1 ; j<=dist ; j++) fl(x,--y);
        for(int j=1 ; j<=dist ; j++) fd(++x,y); dist++;
        for(int j=1 ; j<=dist ; j++) fr(x,++y);
        for(int j=1 ; j<=dist ; j++) fu(--x,y); dist++;
    }for(int i=1 ; i<=dist-1 ; i++) fl(x,--y);

    for(int i=1 ; i<=n ; i++)
        for(int j=1 ; j<=n ; j++) res += v[i][j];
    cout << tot - res;
    return 0;
}
