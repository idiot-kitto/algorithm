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
const ll LL_MAX = 1e18;
const int mod = 1e9 + 7;
const long double PI = 3.141592653589793238462643383279502884197;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

vl v;
ll tree[4*SIZE];
ll init(ll node, ll start, ll end){
    ll mid = (start + end) / 2;
    if(start == end) return tree[node] = v[start];
    else return tree[node] = min(init(node * 2, start, mid), init(node * 2 + 1, mid + 1, end));
}
ll find_min(ll node, ll start, ll end, ll left, ll right)
{
    if(left > end || right < start) return LL_MAX;
    if(left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    ll n1 = find_min(node * 2, start, mid, left, right);
    ll n2 = find_min(node * 2 + 1, mid + 1, end, left, right);
    if(n1 == LL_MAX) return n2;
    else if(n2 == LL_MAX) return n1;
    else return min(n1, n2);
}

int main(){fastio
    string s; cin >> s; v = vl(s.size(),0); ll n = ll(s.size()), ans = 0;
    if(s[0] == '(') v[0] = 1;
    else v[0] = -1;
    for(int i=1 ; i<n ; i++){
        if(s[i] == '(') v[i] = v[i-1] + 1;
        else if(s[i] == ')') v[i] = v[i-1] - 1;
    } init(1, 0, n-1);
    int t; cin >> t;
    while(t--){
        int a, b; cin >> a >> b; a--; b--;
        if(!a){
            if(find_min(1, 0, n-1, b, b) == 0)
                if(find_min(1, 0, n-1, a, b) == 0)
                    ans++;
        }
        else{
            if(find_min(1, 0, n-1, a-1, a-1) == find_min(1, 0, n-1, b, b))
                if(find_min(1, 0, n-1, a, b) >= find_min(1, 0, n-1, a-1, a-1))
                    ans++;
        }
    }cout << ans;

    return 0;
}

// L~R 구간이 올바른 괄호문자열이려면 S[R]-S[L-1] == 0이면서 S[L...R] 의 최솟값이 S[L-1] 이상이어야 한다
// v[a-1] == v[b] && min(v[a], v[a], ..., v[b]) >= v[a-1]
