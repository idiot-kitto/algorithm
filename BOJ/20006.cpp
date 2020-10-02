#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, int> psi;
typedef pair<int,string> pis;
typedef pair<char, int> pci;
typedef pair<int, char> pic;
const int MOD = 1e9 + 7;
const long double PI = 3.141592653589793238462643383279502884197;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

int p, m, room_size;
vector<pis> room[301];
int main()
{ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> p >> m;
    for(int i=0 ; i<p ;i++){
        int l; string s; cin >> l >> s;
        if(!room_size){
            room_size++;
            room[0].push_back({l,s});
        }else{
            bool check = false;
            for(int j=0 ; j<room_size ; j++){
                if(l<=room[j].front().first + 10 && l>=room[j].front().first - 10){
                    if(room[j].size() < m){
                        room[j].push_back({l,s});
                        check = true;
                        break;
                    }
                }
            }
            if(!check){
                room_size++;
                room[room_size-1].push_back({l,s});
            }
        }
    }

    for(int i=0 ; i<room_size ; i++)
        sort(all(room[i]),[](const pis &p1, const pis &p2){
             return p1.second < p2.second;});


    for(int i=0 ; i<room_size ; i++){
        if(room[i].size() == m) cout << "Started!\n";
        else cout << "Waiting!\n";
        
        for(auto iter = room[i].begin() ; iter != room[i].end() ; iter++)
            cout << iter->first << " " << iter->second << "\n";
    }
    return 0;
}
