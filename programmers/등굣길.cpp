#include <bits/stdc++.h>
#define M 1000000007
using namespace std;
int arr[101][101];
int solution(int m, int n, vector<vector<int>> puddles) {
    for(int i=1 ; i<101 ; i++)
        for(int j=1 ; j<101 ; j++)
            arr[i][j] = INT_MAX;
    for(int i=0 ; i<puddles.size() ; i++) arr[puddles[i][1]][puddles[i][0]] = 0;
    for(int i=1 ; i<=m ; i++) {if(arr[1][i]==INT_MAX) arr[1][i] = 1; else break;}
    for(int i=1 ; i<=m ; i++) if(arr[1][i]==INT_MAX) arr[1][i] = 0;
    for(int i=2 ; i<=n ; i++) {if(arr[i][1]==INT_MAX) arr[i][1] = 1; else break;}
    for(int i=2 ; i<=n ; i++) if(arr[i][1]==INT_MAX) arr[i][1] = 0;
    for(int i=2 ; i<=max(m,n) ; i++){
        for(int j=i ; j<=m ; j++){
            if(!arr[i][j]) continue;
            arr[i][j] = (arr[i-1][j] + arr[i][j-1]) % M;
        }
        for(int j=i ; j<=n ; j++){
            if(!arr[j][i]) continue;
            arr[j][i] = (arr[j-1][i] + arr[j][i-1]) % M;
        }
    }
    if(arr[n][m] == INT_MAX) return 0;
    else return arr[n][m];
}
