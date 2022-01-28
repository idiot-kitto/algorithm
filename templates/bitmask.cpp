#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
const ll mod = 1e9 + 7;
const long double PI = 3.141592653589793238462643383279502884197;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

int main(){fastio

    // 마지막 비트가 1인지 확인
    int num1 = 123;
    if(num1 & 1) cout << "YES\n";
    if(!(num1 & 1)) cout << "NO\n";

    // 우측에서부터 n번째 비트가 1인지 확인
    int num2 = 16, n = 4;
    if(num2 & (1 << (n - 1))) cout << "YES\n";
    if(!(num2 & (1 << (n - 1)))) cout << "NO\n";
    
    // 2의 보수 만들기 + 출력
    int num3 = 7;
    int num3Complement = ~num3 + 1; // 2의 보수 : 모든 비트 반전 후 + 1
    
    // 출력
    cout << "num3 : "; int tmp = num3; vi v1;
    while(tmp) {
        v1.pb(tmp & 1);
        tmp >>= 1;
    } reverse(all(v1)); // 우측 비트부터 벡터에 담으므로 reverse 해준다.
    for(auto i : v1) cout << i; cout << '\n';
    
    // 자리수 맞춰 출력. 7, 15같은 모든 비트가 1인 경우는 따로 체크가 필요하다.
    cout << "num3 Complement : ";
    int tmp2 = num3Complement; tmp = num3; vi v2;
    while(tmp) {
        v2.pb(tmp2 & 1);
        tmp >>= 1; tmp2 >>= 1;
    } reverse(all(v2)); // 우측 비트부터 벡터에 담으므로 reverse 해준다.
    for(auto i : v2) cout << i; cout << '\n';

    return 0;
}