#include <bits/stdc++.h>
using namespace std;
int n, k, arr[100001], check[100001];
queue<int> q;

void solve(int current, int next, int delta)
{
    if(0<=next && next<=100000 && !check[next]){
        arr[next] = min(arr[next], arr[current] + delta);
        if(!check[next]) q.push(next);
        check[next] = 1;
    }
}
int main()
{ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for(int i=0 ; i<100004 ; ++i) arr[i] = INT_MAX;
    cin >> n >> k;
    arr[n] = 0; check[n] = 1; q.push(n);

    while(!q.empty()){
        if(check[k]){
            cout << arr[k];
            break;
        }
        int current = q.front(); q.pop();
        solve(current, current * 2, 0);
        solve(current, current - 1, 1);
        solve(current, current + 1, 1);
    }
    return 0;
}
