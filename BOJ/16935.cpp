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
int n, m, r;
vvi v;
void func(int k){
    if(k == 1){ // 상하 반전
        for(int i=0 ; i<n/2 ; i++)
            for(int j=0 ; j<m ; j++)
                swap(v[i][j], v[n-1-i][j]);
    }else if(k == 2){ // 좌우 반전
        for(int i=0 ; i<n ; i++)
            for(int j=0 ; j<m/2 ; j++)
                swap(v[i][j], v[i][m-1-j]);
    }else if(k == 3){ // 오른쪽 90도 회전
	// 정사각일때, (i,j) --> (j, n-1-i) 
        swap(n,m);
        vvi tmp(n,vi(m));
        for(int i=0 ; i<n ; i++)
            for(int j=0 ; j<m ; j++)
                tmp[i][j] = v[m-1-j][i];
        for(int i=0 ; i<n ; i++)
            for(int j=0 ; j<m ; j++)
                v[i][j] = tmp[i][j];
    }else if(k == 4){ // 왼쪽 90도 회전
	// 정사각일때, (i,j) --> (n-1-j, i)
        swap(n,m);
        vvi tmp(n,vi(m));
        for(int i=0 ; i<n ; i++)
            for(int j=0 ; j<m ; j++)
                tmp[i][j] = v[j][n-1-i];
        for(int i=0 ; i<n ; i++)
            for(int j=0 ; j<m ; j++)
                v[i][j] = tmp[i][j];
    }else if(k == 5){ // 부분 시계 회전
        int nn = n/2, mm = m/2;
        vvi tmp(nn,vi(mm));
        for(int i=0 ; i<nn ; i++)
            for(int j=0 ; j<mm ; j++)
                tmp[i][j] = v[i][j];
        for(int i=0 ; i<nn ; i++)
            for(int j=0 ; j<mm ; j++)
                v[i][j] = v[i+nn][j];
        for(int i=nn ; i<n ; i++)
            for(int j=0 ; j<mm ; j++)
                v[i][j] = v[i][j+mm];
        for(int i=nn ; i<n ; i++)
            for(int j=mm ; j<m ; j++)
                v[i][j] = v[i-nn][j];
        for(int i=0 ; i<nn ; i++)
            for(int j=mm ; j<m ; j++)
                v[i][j] = tmp[i][j-mm];
    }else if(k == 6){ // 부분 반시계 회전 
        int nn = n/2, mm = m/2;
        vvi tmp(nn,vi(mm));
        for(int i=0 ; i<nn ; i++)
            for(int j=0 ; j<mm ; j++)
                tmp[i][j] = v[i][j];
        for(int i=0 ; i<nn ; i++)
            for(int j=0 ; j<mm ; j++)
                v[i][j] = v[i][j+mm];
        for(int i=0 ; i<nn ; i++)
            for(int j=mm ; j<m ; j++)
                v[i][j] = v[i+nn][j];
        for(int i=nn ; i<n ; i++)
            for(int j=mm ; j<m ; j++)
                v[i][j] = v[i][j-mm];
        for(int i=nn ; i<n ; i++)
            for(int j=0 ; j<mm ; j++)
                v[i][j] = tmp[i-nn][j];
    }
}
int main(){fastio
    cin >> n >> m >> r; v = vvi(102,vi(102));
    for(int i=0 ; i<n ; i++)
        for(int j=0 ; j<m ; j++) cin >> v[i][j];
    for(int i=0 ; i<r ; i++){
        int a; cin >> a;
        func(a);
    }
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++)
            cout << v[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}
