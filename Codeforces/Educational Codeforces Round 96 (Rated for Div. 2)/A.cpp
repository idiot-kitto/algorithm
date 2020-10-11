#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, int> psi;
typedef pair<char, int> pci;
typedef pair<int, char> pic;
const int MOD = 1e9 + 7;
const long double PI = 3.141592653589793238462643383279502884197;
 
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
 
int t, n;
 
int main()
{ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        int a = 0, b = 0, c = 0;
        if(n==1 || n==2 || n==4) {cout << -1 << "\n"; continue;}
        else{
            while(n){
                if(n%3==0){a+=n/3;n=0;}
                else if(n%5==0){b+=n/5;n=0;}
                else if(n%7==0){c+=n/7;n=0;}
                else if(n%8==0){a+=n/8;b+=n/8;n=0;}
                else if(n%11==0){a+=n/11*2;b+=n/11;n=0;}
                else if(n%13==0){a+=n/13;b+=n/13*2;n=0;}
                else if(n%15==0){a+=n/15;b+=n/15;c+=n/15;n=0;}
                else{
                    n-=3;a++;
                }
            }
        }
        cout << a << " " << b << " " << c << "\n";
    }
    return 0;
}
