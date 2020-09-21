#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
vector<int> solution(int n) {
    vector<int> answer;
    int cnt = 0;
    for(int i=1 ; i<=n ; i++) cnt+=i;
    int val = 0, a = 1, b = 1;
    while(1){if(val == cnt) break;
        while(1){
            if(a>n) {a--;break;}
            if(dp[a][b]) {a--;break;}
            if(val == cnt) break;
            dp[a++][b] = ++val;
        }b++;
        while(1){
            if(b>n) {b--;break;}
            if(dp[a][b]) {b--;break;}
            if(val == cnt) break;
            dp[a][b++] = ++val;
        }a--;b--;
        while(1){
            if(dp[a][b]) {a++;b++;break;}
            if(val == cnt) break;
            dp[a--][b--] = ++val;
        }a++;
    }
    
    for(int i=1 ; i<=n ; i++)
        for(int j=1 ; j<=i ; j++)
            answer.push_back(dp[i][j]);
    return answer;
}
