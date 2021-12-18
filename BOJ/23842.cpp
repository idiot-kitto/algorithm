#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define pb push_back

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
typedef vector<pii> vpii;
typedef vector<pll> vpll;
const int mod = 1e9 + 7;
const long double PI = 3.141592653589793238462643383279502884197;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

int arr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main(){fastio
    map<int, pair<pii,pii>> mp;
    map<int, int> check;
    for(int a=0 ; a<10 ; a++) {
        for(int b=0 ; b<10 ; b++) {
            for(int c=0 ; c<10 ; c++) {
                for(int d=0 ; d<10 ; d++) {
                    int cnt = arr[a] + arr[b] + arr[c] + arr[d];
                    int res = a * 10 + b + c * 10 + d;
                    if(res >= 100) continue;
                    cnt += arr[res / 10];
                    cnt += arr[res % 10];
                    mp[cnt+4] = {{a,b},{c,d}};
                    check[cnt+4] = 1;
                }
            }
        }
    }

    int n; cin >> n;
    if(!check[n]) cout << "impossible";
    else {
        int a = mp[n].first.first;
        int b = mp[n].first.second;
        int c = mp[n].second.first;
        int d = mp[n].second.second;
        cout << a << b << '+' << c << d << '=' << a*10+b+c*10+d;
    }

    return 0;
}
