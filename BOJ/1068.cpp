#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define SIZE 100001

typedef long long ll;
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

int n, root, ans, d;
vector<vector<int>> tree;
void dfs(int node){
    int child = 0;
    int k = tree[node].size();
    for(int i=0 ; i<k ; i++){
        if(tree[node][i] == d) continue;
        dfs(tree[node][i]); child++;
    }
    if(!child) ans++;
}

int main(){fastio
    cin >> n; tree = vector<vector<int>>(n);
    for(int i=0 ; i<n ; i++){
        int a; cin >> a;
        if(a == -1){root = i; continue;}
        tree[a].pb(i);
    }cin >> d;
    if(root == d) cout << 0;
    else{
        dfs(root);
        cout << ans;
    }

    return 0;
}
