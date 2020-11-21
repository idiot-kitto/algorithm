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

int k;

void func(char c1, char c2, int hole){
    int a, b, c, d;
    if(c1 == 'R' && c2 == 'D' && hole == 0){here0:; a = 3; b = 2; c = 1; d = 0;}
    else if(c1 == 'R' && c2 == 'D' && hole == 1){here1:; a = 2; b = 3; c = 0; d = 1;}
    else if(c1 == 'R' && c2 == 'D' && hole == 2){here2:; a = 1; b = 0; c = 3; d = 2;}
    else if(c1 == 'R' && c2 == 'D' && hole == 3){here3:; a = 0; b = 1; c = 2; d = 3;}
    else if(c1 == 'R' && c2 == 'U' && hole == 0) goto here2;
    else if(c1 == 'R' && c2 == 'U' && hole == 1) goto here3;
    else if(c1 == 'R' && c2 == 'U' && hole == 2) goto here0;
    else if(c1 == 'R' && c2 == 'U' && hole == 3) goto here1;
    else if(c1 == 'L' && c2 == 'D' && hole == 0) goto here1;
    else if(c1 == 'L' && c2 == 'D' && hole == 1) goto here0;
    else if(c1 == 'L' && c2 == 'D' && hole == 2) goto here3;
    else if(c1 == 'L' && c2 == 'D' && hole == 3) goto here2;
    else if(c1 == 'L' && c2 == 'U' && hole == 0) goto here3;
    else if(c1 == 'L' && c2 == 'U' && hole == 1) goto here2;
    else if(c1 == 'L' && c2 == 'U' && hole == 2) goto here1;
    else if(c1 == 'L' && c2 == 'U' && hole == 3) goto here0;

    for(int i=0 ; i<(int)pow(2,k-1) ; i++){
        for(int j=0 ; j<(int)pow(2,k-1) ; j++) cout << a << ' ' << b << ' '; cout << '\n';
        for(int j=0 ; j<(int)pow(2,k-1) ; j++) cout << c << ' ' << d << ' '; cout << '\n';
    }
}

int main(){fastio
    cin >> k; char lc1, lc2;
    for(int i=0 ; i<k*2 ; i++){
        char c; cin >> c;
        if(c == 'R' || c == 'L') lc1 = c;
        if(c == 'U' || c == 'D') lc2 = c;
    } int h; cin >> h;
    func(lc1, lc2, h);

    return 0;
}
