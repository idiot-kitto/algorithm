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
 
int ok(int k){
    if(k==0) return 0;
    else if(k==1) return 1;
    else if(k==2) return 5;
    else if(k==3) return -1;
    else if(k==4) return -1;
    else if(k==5) return 2;
    else if(k==6) return -1;
    else if(k==7) return -1;
    else if(k==8) return 8;
    else if(k==9) return -1;
}
 
int main(){fastio
    int t; cin >> t;
    while(t--){
        int h, m; cin >> h >> m;
        string s; cin >> s;
        int a = s[0] - '0';
        int b = s[1] - '0';
        int c = s[3] - '0';
        int d = s[4] - '0';
 
        for(int i=a ; i<10 ; i++){
            for(int j=(i==a?b:0) ; j<10 ; j++){
                if(i*10+j<h){
                    for(int k=((i==a&&j==b)?c:0) ; k<10 ; k++){
                        for(int l=((i==a&&j==b&&k==c)?d:0) ; l<10 ; l++){
                            if(k*10+l<m){
                                if(ok(i) != -1 && ok(j) != -1 && ok(k) != -1 && ok(l) != -1){
                                    if(ok(l)*10+ok(k) < h && ok(j)*10+ok(i) < m){
                                        cout << i << j << ':' << k << l << '\n';
                                        goto here;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }cout << "00:00\n";
        here:;
    }
 
    return 0;
}
